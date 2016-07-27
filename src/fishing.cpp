#include <stdio.h>
#include <math.h>
//#include <conio.h>

int main()
{
	//freopen("input.txt", "r", stdin);
	int N, M, X, Y, T;
	while (~scanf("%d %d %d %d %d", &N, &M, &X, &Y, &T))
	{
		int i, j;

		double ps, pc, t;

		double sump = 0.0;

		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < M; ++j)
			{
				scanf("%lf", &t);
				sump += t;
				if (i == X - 1 && j == Y - 1)
				{
					pc = t;
				}
			}
		}
		
		sump /= (N * M * 1.0);

		pc = 1.0 - pow(1.0 - pc, T);
		ps = 1.0 - pow(1.0 - sump, T);

		if (fabs(ps - pc) < 1e-8)
		{
			printf("equal\n");
			printf("%.2lf\n", ps);
		}
		else if (ps < pc)
		{
			printf("cc\n");
			printf("%.2lf\n", pc);
		} 
		else 
		{
			printf("ss\n");
			printf("%.2lf\n", ps);
		}
	}
	//getch();
	return 0;
}