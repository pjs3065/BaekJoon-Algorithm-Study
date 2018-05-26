#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int n, d, k, j;
	scanf("%d %d %d %d", &n, &d, &k, &j);

	//전체 인원수
	int count = n-1; // 6명일시 5번 탈락 시키기 위함

	//사람과 그 사람의 탈락 여부
	vector<int> man (n + 1);
	vector<int> check (n + 1);

	//시계방향일 경우
	if(d == 1)
	{
		int start = 0;
		int p = 1;

		while(count != 0)
		{
			int next = k;

			//첫 시작
			if(start == 0)
			{
				start = 1;
				p = p + k;

				if(p > n)
				{
					p = (p % n);
				}

				check[p] = 1; //탈락
				count--;
			}

			// 처음 외의 나머지
			else
			{
				while(next != 0)
				{
					p = p + 1;

					if(p > n)
					{
						p = (p % n);
					}

					if(check[p] == 1)
					{
						continue;
					}

					else
					{
						next -= 1;
					}
				}

				//해당 순서를 찾고 탈락시키고
				check[p] = 1;

				//남아 있는 인원 감소
				count --;
			}

			//k는 j 만큼 증가
			k = k + j;
		}
	}

	//시계 반대 방향일 경우
	else if (d == 0)
	{
		int start = 0;
		int p = 1;

		while(count != 0)
		{
			int next = k;

			//첫 시작
			if(start == 0)
			{
				start = 1;
				p = p - k;

				if(p < 1)
				{
					p = p + n;
				}

				check[p] = 1; //탈락
				count--;
			}

			// 처음 외의 나머지
			else
			{
				//다음 순서로 갈 때
				while(next != 0)
				{
					p = p - 1;

					if(p < 1)
					{
						p = p + n;
					}

					if(check[p] == 1)
					{
						continue;
					}

					else
					{
						next -= 1;
					}
				}

				//해당 순서를 찾고 탈락시키고
				check[p] = 1;

				//남아 있는 인원 감소
				count --;
			}
			//k는 j만큼 상승 
			k = k + j;
		}
	}

	//결과 값 출력
	for(int i = 1; i <= n; i++)
	{
		if(check[i] == 0)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}