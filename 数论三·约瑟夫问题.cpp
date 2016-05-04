#include <stdio.h>

int josephus(int N, int K)
{
	int ret;
	int i;

	if (1 == N)
		return 0;

	if (N < K)
	{
		ret = 0;
		for (i = 2; i <= N; i++)
		{
			ret = (ret + K) % i;
		}

		return ret;
	}

	ret = josephus(N - N / K, K);
	if (ret < N % K)
		ret = ret - N % K + N;
	else
		ret = ret - N % K + (ret - N % K) / (K - 1);

	return ret;
}

int main()
{
	int t; // 测试次数
	int n; // 人数
	int k; // 第K个数淘汰
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d", &n, &k);

		printf("%d\n",josephus(n, k));
	}

	return 0;
}