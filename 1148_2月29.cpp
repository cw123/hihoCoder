#include <stdio.h>
#include <string.h>

#define MAX_MONTH_LEN 10

char monthList[][MAX_MONTH_LEN] =
{
	"January", "February", "March", "April",
	"May", "June", "July", "August", "September",
	"October", "November" , "December"
};

// 传入的月份和天数，比2月29号相比
int compare2_29(char *monthString, int day)
{
	int i;
	int month = 0;
	for (i = 0; i < 12; i++)
	{
		if (!strcmp(monthList[i], monthString))
		{
			month = i + 1;
		}
	}

	if (month != 2)
	{
		return month - 2;
	}
	else
	{
		return day - 29;
	}
}

// 计算从第0年到第year年有多少个闰月
int resultFrom0year(int year)
{
	return year / 4 - year / 100 + year / 400 + 1;
}

int calcResult()
{
	char startMonth[MAX_MONTH_LEN] = { 0 };
	char endMonth[MAX_MONTH_LEN] = { 0 };
	int startDay, startYear;
	int endDay, endYear;

	scanf("%s %d, %d", startMonth, &startDay, &startYear);
	scanf("%s %d, %d", endMonth, &endDay, &endYear);
	
	if (compare2_29(startMonth, startDay) > 0)
	{
		startYear++;
	}

	if (compare2_29(endMonth, endDay) < 0)
	{
		endYear--;
	}

	return resultFrom0year(endYear) - resultFrom0year(startYear - 1);
}

int main()
{
	int T, i;
	int result = 0;

	scanf("%d", &T);
	for (i = 1; i <= T; i++)
	{
		result = calcResult();
		printf("Case #%d: %d\n", i, result);
	}
	
	return 0;
}

