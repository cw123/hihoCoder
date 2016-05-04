// Eular质数筛选法
// http://hihocoder.com/contest/hiho93/problem/1

#include <stdio.h>

bool isPrime[1000001];
int primeList[1000001];
int primeCount = 0;

int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		isPrime[i] = true;
	}

	for (int i = 2; i <= N; i++)
	{
		if (isPrime[i])
		{
			primeCount++;
			primeList[primeCount] = i;
		}

		for (int j = 1; j <= primeCount; j++)
		{
			if (i * primeList[j] > N)
			{
				break;
			}

			isPrime[i * primeList[j]] = false;

			if (!(i % primeList[j]))
			{
				break;
			}
		}
	}

	printf("%d\n", primeCount);
	return 0;
}