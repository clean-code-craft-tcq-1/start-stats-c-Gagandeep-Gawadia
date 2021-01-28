#include "stats.h"
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) 
{
        struct Stats s;
	
	if(setlength != 0) //number set is not empty
        {   
      	      //initialize members with 0
   	      s.average = 0.0f;
	      s.min = numberset[0];
	      s.max = numberset[0];

	      for (int loop_counter=0; loop_counter < setlength; loop_counter++)
	      {

		 if (s.min > numberset[loop_counter])
		 { 
				 s.min = numberset[loop_counter];
		 }
		 if ( s.max <  numberset[loop_counter])
		 { 
				 s.max = numberset[loop_counter];
		 }

			 s.average += numberset[loop_counter];

	       }
	       s.average /= (float)setlength;
	}

	else //number set is empty
	{ 
	     s.average = NAN;
	     s.min = NAN;
	     s.max = NAN;
	 }

    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
int sizeofalertbuffer = 0;

 void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
	for (int loop_counter = 0; loop_counter < sizeofalertbuffer; loop_counter++)
	{
		if (computedStats.max > maxThreshold)
		{

			alerters[loop_counter]();

		}
	}
 }

 void emailAlerter()
 {
	 emailAlertCallCount = 1;
 }
 void ledAlerter()
 {
	 ledAlertCallCount = 1;
 }

