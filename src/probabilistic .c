#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>

double map[21][21];

int main()
{
	//freopen("input.txt", "r", stdin);
	int N, M, K, X, Y;
	while (~scanf("%d %d %d", &N, &M, &K))
	{
		int i, j;

		memset(map, 0, sizeof(map));
		for (i = 0; i < K; ++i)
		{
			scanf("%d %d", &X, &Y);
			map[X][Y] = 1.0;
		}
		map[1][1] = 1.0;
		for (i = 1; i <= N; ++i)
		{
			for (j = 1; j <= M; ++j)
			{
				if (i == 1 && j == 1)
				{
					continue;
				}
				if (fabs(map[i][j]-1.0f) < 1e-6)
				{
					map[i][j] = 0.0;
				}
				else
				{
					map[i][j] = map[i - 1][j] * 0.5 + map[i][j - 1] * 0.5;
					if (j == M)
					{
						map[i][j] += map[i - 1][j] * 0.5;
					}
					if (i == N)
					{
						map[i][j] += map[i][j - 1] * 0.5;
					}
				}
			}
		}

		printf("%.2lf\n", map[N][M]);
	}
	return 0;
}