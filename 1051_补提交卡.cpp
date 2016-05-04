#include <stdio.h>

#define MAX_NUM 100

int main()
{
	int T; // (1 <= T <= 10)，代表测试数据的组数
	int M; // 0 <= N, M <= 100, 补提交卡的个数
	int N; // 0 <= N, M <= 100, N个整数
	int a[MAX_NUM + 2] = {0};

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		scanf("%d", &M);

		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
		}

		a[N + 1] = MAX_NUM + 1;

		if (M >= N)
		{
			printf("%d\n", MAX_NUM);
			continue;
		}
		
		int max = 0;
		for (int i = 1; i <= N - M + 1; i++)
		{
			if (max < a[i + M] - 1 - a[i - 1])
			{
				max = a[i + M] - 1 - a[i - 1];
			}
		}

		printf("%d\n", max);
	}

	return 0;
}