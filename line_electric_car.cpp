#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int t, count = 1;
	scanf("%d", &t);

	while(count <= t)
	{
		int tc;
		scanf("%d", &tc);

		//충전가능
		vector<int> e(tc);

		for(int i = 0; i < tc; i++)
		{
			scanf("%d", &e[i]);
		}

		//소모 에너지
		vector<int> c(tc);

		for(int i = 0; i < tc; i++)
		{
			scanf("%d", &c[i]);
		}

		int l = 0;
		int r = 0;

		//정답변수
		int ans = 0;

		//게이지
		int charge = 0;
		charge = e[l];

		while(l < tc)
		{
			//게이지가 부족할 경우 다른 경로부터 시작
			if(charge < c[r % tc]) //순환하기 위해서
			{
				l++;

				if(l == tc)
				{
					break;
				}

				charge = e[l];
				continue;
			}

			//다음 스테이지로 넘어 갈 수 있는 게이지가 있을 경우
			else
			{
				charge -= c[r % tc];
				r++;
				charge += e[r % tc];
			}

			//한바퀴 다 돌았으면 정답 출력
			if(l == r)
			{
				ans = l;
				break;
			}
		}

		printf("%d\n", ans);
		count++;
	}

	return 0;


}