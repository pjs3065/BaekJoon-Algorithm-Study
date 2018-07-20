#include<stdio.h>
#include<vector>

using namespace std;

int m_y[4] = {0,-1,0,1};
int m_x[4] = {1,0,-1,0};

int main()
{
	//테스트케이스
	int t, count = 1;
	scanf("%d", &t);

	//전체 드레곤 커브 맵 만들기
	vector< vector<int> > map;
	for(int i = 0; i < 101; i++)
	{
		vector<int> element(101);
		map.push_back(element);
	}

	while(count <= t)
	{
		//입력
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g); // x, y, d : 방향, g : 세대

		//처음 시작점 초기화
		map[y][x] = 1;

		//처음 이동
		int end_y = y + m_y[d];  
		int end_x = x + m_x[d];

		//움직인 점 찍기
		map[end_y][end_x] = 1;

		//방향 저장
		vector<int> re;
		re.push_back(d);

		//세대 반복
		while(g--)
		{
			int len = re.size();
			//방향 저장한 만큼 반복하기
			for(int i = len - 1; i >= 0; i--)
			{
				//방향 바꾸기
				if(re[i] == 3) d = 0;
				else d = re[i] + 1;

				//방향에 따른 이동 좌표
				end_y = end_y + m_y[d];
				end_x = end_x + m_x[d];

				//방문 기록
				map[end_y][end_x] = 1;

				//새로운 방향 기록하기
				re.push_back(d);
			}
		}
		count++;
	}

	int sq_count = 0;

	//사각형 갯수 세기
	for(int i = 0; i < 101; i++)
	{
		for(int j = 0; j < 101; j++)
		{
			if(i + 1 >= 101  || j + 1 >= 101) continue;
			if(map[i][j] == 1 && map[i+1][j]== 1 && map[i][j+1] == 1 && map[i+1][j+1] == 1)
			{
				sq_count++;
			}
		}
	}

	printf("%d\n",sq_count);
	return 0;
}