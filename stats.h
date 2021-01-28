
struct Stats {

	float average;
	float max;
	float min;
};

typedef void(*alerter_funcptr)();

extern int emailAlertCallCount;
extern int ledAlertCallCount;
extern int sizeofalertbuffer;

// function declarations
struct Stats compute_statistics(const float* numberset, int setlength);

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

void emailAlerter();
void ledAlerter();
