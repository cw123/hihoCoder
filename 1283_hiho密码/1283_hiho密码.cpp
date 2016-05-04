#include <stdio.h>

#define MAX_LENGTH 1001

int main()
{
	int N;
	int i;
	int end;
	int A[MAX_LENGTH];

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	end = 0;
	for (i = N - 1; i > 0; i--)
	{
		if (A[i] < A[i - 1])
		{
			end = i - 1;
			break;
		}
	}

	for (i = 0; i <= end; i++)
	{
		printf("%d ", A[i]);
	}

	return 0;
}
