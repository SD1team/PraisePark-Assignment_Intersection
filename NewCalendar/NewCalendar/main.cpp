#include <cstdio>

struct Calendar {
	int numOfMonthsPerYear;
	int numOfDaysPerMonth;
	int numOfDaysPerWeek;
};

int getNumOfCalendarLines(Calendar calendar) {
	
	int numOfLines = 0;
	int lastDayRowOfMonth = 0;

	for(int i=0; i<calendar.numOfMonthsPerYear; i++) {
		
		numOfLines += calendar.numOfDaysPerMonth / calendar.numOfDaysPerWeek;
		if(calendar.numOfDaysPerMonth % calendar.numOfDaysPerWeek) numOfLines++;

		if(calendar.numOfMonthsPerYear == 1) break;
		calendar.numOfDaysPerMonth -= lastDayRowOfMonth;
		lastDayRowOfMonth = calendar.numOfDaysPerMonth % calendar.numOfDaysPerWeek;
		calendar.numOfDaysPerMonth += lastDayRowOfMonth;
	}

	return numOfLines;
}

int main() {

	int numOfTestCase = 0;

	printf("INPUT\n");
	scanf("%d", &numOfTestCase);
	fflush(stdin);

	Calendar* calendars = new Calendar[numOfTestCase];
	if(calendars == NULL) return 0;

	for(int i=0; i<numOfTestCase; i++) {
		scanf("%d %d %d", &calendars[i].numOfMonthsPerYear, 
						  &calendars[i].numOfDaysPerMonth, 
						  &calendars[i].numOfDaysPerWeek);
		fflush(stdin);
	}

	printf("\nOUTPUT\n");
	int numOfCalendarLines = 0;
	for(int i=0; i<numOfTestCase; i++) {
		numOfCalendarLines = getNumOfCalendarLines(calendars[i]);
		printf("Case #%d: %d\n", i+1, numOfCalendarLines);
	}

	delete []calendars;

	return 0;
}