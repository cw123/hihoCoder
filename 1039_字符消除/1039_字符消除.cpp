#include <stdio.h>
#include <string.h>

typedef enum 
{
	INIT,
	SAME,
	NOT_SAME
}STATUS;

#define MAX_LEN 110

bool delDedupChar(char *strings)
{
	int length;
	int index = 0;
	char pre = 0;
	STATUS status = INIT;
	int i;

	length = strlen(strings);

	for (i = 0; i < length; i++)
	{
		if (INIT == status)
		{
			pre = strings[i];
			status = NOT_SAME;
			continue;
		}

		if (NOT_SAME == status)
		{
			if (pre == strings[i])
			{
				status = SAME;
			}
			else
			{
				strings[index++] = pre;
				pre = strings[i];
			}
		}
		else
		{
			if (pre == strings[i])
			{
				continue;
			}
			else
			{
				pre = strings[i];
				status = NOT_SAME;
			}
		}
	}

	if (NOT_SAME == status)
	{
		strings[index++] = pre;
	}

	strings[index] = '\0';

	return index == length;
}

int calcResult(char *strings)
{
	int min = MAX_LEN;
	int length = strlen(strings);
	int leftLength;
	char temp[MAX_LEN];
	int i;
	int j;

	for (i = 0; i < length; i++)
	{
		for (j = 0; j < 3; j++)
		{
			memcpy(temp, strings, i);
			temp[i] = 'A' + j;
			memcpy(temp + i + 1, strings + i, length - i + 1);
			while (!delDedupChar(temp))
			{
				;
			}

			leftLength = strlen(temp);

			min = min < leftLength ? min : leftLength;
		}
	}

	return min;
}

int main()
{
	int T;
	char strings[MAX_LEN];
	int len;
	int result;
	int i;
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		memset(strings, 0, MAX_LEN);
		scanf("%s", strings);
		len = strlen(strings);
		result = calcResult(strings);
		printf("%d\n", len - result + 1);
	}

	return 0;
}