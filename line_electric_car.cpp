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

		//��������
		vector<int> e(tc);

		for(int i = 0; i < tc; i++)
		{
			scanf("%d", &e[i]);
		}

		//�Ҹ� ������
		vector<int> c(tc);

		for(int i = 0; i < tc; i++)
		{
			scanf("%d", &c[i]);
		}

		int l = 0;
		int r = 0;

		//���亯��
		int ans = 0;

		//������
		int charge = 0;
		charge = e[l];

		while(l < tc)
		{
			//�������� ������ ��� �ٸ� ��κ��� ����
			if(charge < c[r % tc]) //��ȯ�ϱ� ���ؼ�
			{
				l++;

				if(l == tc)
				{
					break;
				}

				charge = e[l];
				continue;
			}

			//���� ���������� �Ѿ� �� �� �ִ� �������� ���� ���
			else
			{
				charge -= c[r % tc];
				r++;
				charge += e[r % tc];
			}

			//�ѹ��� �� �������� ���� ���
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