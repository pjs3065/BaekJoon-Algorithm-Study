#include<stdio.h>
#include<vector>

using namespace std;

int m_y[4] = {0,-1,0,1};
int m_x[4] = {1,0,-1,0};

int main()
{
	//�׽�Ʈ���̽�
	int t, count = 1;
	scanf("%d", &t);

	//��ü �巹�� Ŀ�� �� �����
	vector< vector<int> > map;
	for(int i = 0; i < 101; i++)
	{
		vector<int> element(101);
		map.push_back(element);
	}

	while(count <= t)
	{
		//�Է�
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g); // x, y, d : ����, g : ����

		//ó�� ������ �ʱ�ȭ
		map[y][x] = 1;

		//ó�� �̵�
		int end_y = y + m_y[d];  
		int end_x = x + m_x[d];

		//������ �� ���
		map[end_y][end_x] = 1;

		//���� ����
		vector<int> re;
		re.push_back(d);

		//���� �ݺ�
		while(g--)
		{
			int len = re.size();
			//���� ������ ��ŭ �ݺ��ϱ�
			for(int i = len - 1; i >= 0; i--)
			{
				//���� �ٲٱ�
				if(re[i] == 3) d = 0;
				else d = re[i] + 1;

				//���⿡ ���� �̵� ��ǥ
				end_y = end_y + m_y[d];
				end_x = end_x + m_x[d];

				//�湮 ���
				map[end_y][end_x] = 1;

				//���ο� ���� ����ϱ�
				re.push_back(d);
			}
		}
		count++;
	}

	int sq_count = 0;

	//�簢�� ���� ����
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