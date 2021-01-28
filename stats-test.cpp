#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"

#include <stdlib.h>
#include <math.h>

TEST_CASE("reports average, minimum and maximum","[compute_statistics]") {
	float numberset[] = {1.5f, 8.9f, 3.2f, 4.5f};
    float epsilon = 0.001f;
   
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    
    //Function call
    struct Stats computedStats = compute_statistics(numberset, setlength);
    
    //Expected  output
    REQUIRE(abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array","[compute_statistics]") {
   
    //function call
    Stats computedStats = compute_statistics(0, 0);
   
    //Expected  output
	REQUIRE(computedStats.average != computedStats.average);
    REQUIRE(computedStats.min != computedStats.average);
    REQUIRE(computedStats.max != computedStats.average);
}

TEST_CASE("raises alerts when max is greater than threshold","[check_and_alert]") {
    // create additional .c and .h files
    // containing the emailAlerter, ledAlerter functions
    alerter_funcptr alerters[] = {emailAlerter, ledAlerter};
    float numberset[] = {99.8f, 34.2f, 4.5f};
	const float maxThreshold = 10.2f;
    
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    sizeofalertbuffer = sizeof(alerters) / sizeof(alerters[0]);
    
    Stats computedStats = compute_statistics(numberset, setlength);

    //Initialize call counters for alert with zero 
	emailAlertCallCount = 0;
	ledAlertCallCount = 0;
    
    //function call
    check_and_alert(maxThreshold, alerters, computedStats);

   	//Expected  output
    REQUIRE(emailAlertCallCount == 1);
    REQUIRE(ledAlertCallCount == 1);
}
