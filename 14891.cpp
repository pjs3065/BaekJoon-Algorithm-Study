#include<stdio.h>
#include<math.h>
#include<deque>

using namespace std;

int main()
{
	deque<int> de[5];
	for(int i = 1; i < 5; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			int pole;
			scanf("%1d", &pole);
			de[i].push_back(pole);
		}
	}

	int re;
	scanf("%d", &re);

	while(re--)
	{
		int topni_num;
		int way;
		scanf("%d %d", &topni_num, &way);

		//��� ��ȣ�� 1�ΰ��
		if(topni_num == 1)
		{
			//�ð� �ݴ� ������ ���
			if(way == -1)
			{
				int temp1 = de[1][2];
				int att1 = de[1][0];

				de[1].pop_front();
				de[1].push_back(att1);

				if(temp1 != de[2][6])
				{
					int temp2 = de[2][2];
					int att2 = de[2][7];

					de[2].pop_back();
					de[2].push_front(att2);

					if(temp2 != de[3][6])
					{
						int temp3 = de[3][2];
						int att3 = de[3][0];

						de[3].pop_front();
						de[3].push_back(att3);

						if(temp3 != de[4][6])
						{
							int att4 = de[4][7];
							de[4].pop_back();
							de[4].push_front(att4);
						}
					}
				}
			}
			//1�̰� �ð������ ���
			else
			{
				int temp1 = de[1][2];
				int att1 = de[1][7];

				de[1].pop_back();
				de[1].push_front(att1);

				if(temp1 != de[2][6])
				{
					int temp2 = de[2][2];
					int att2 = de[2][0];

					de[2].pop_front();
					de[2].push_back(att2);

					if(temp2 != de[3][6])
					{
						int temp3 = de[3][2];
						int att3 = de[3][7];

						de[3].pop_back();
						de[3].push_front(att3);

						if(temp3 != de[4][6])
						{
							int att4 = de[4][0];
							de[4].pop_front();
							de[4].push_back(att4);
						}
					}
				}
			}
		}

		//��Ϲ����� 2�ΰ��
		else if(topni_num == 2)
		{
			//�ð� �ݴ������ ���
			if(way == -1)
			{
				int temp2_1 = de[2][6];
				int temp2_2 = de[2][2];

				int att2 = de[2][0];

				de[2].pop_front();
				de[2].push_back(att2);

				if(temp2_1 != de[1][2])
				{
					int att1 = de[1][7];

					de[1].pop_back();
					de[1].push_front(att1);
				}

				if(temp2_2 != de[3][6])
				{
					int temp3 = de[3][2];
					int att3 = de[3][7];

					de[3].pop_back();
					de[3].push_front(att3);

					if(temp3 != de[4][6])
					{
						int att4 = de[4][0];
						de[4].pop_front();
						de[4].push_back(att4);
					}
				}
			}

			//2�̰� �ð������ ���
			else
			{
				int temp2_1 = de[2][6];
				int temp2_2 = de[2][2];

				int att2 = de[2][7];

				de[2].pop_back();
				de[2].push_front(att2);

				if(temp2_1 != de[1][2])
				{
					int att1 = de[1][0];

					de[1].pop_front();
					de[1].push_back(att1);
				}

				if(temp2_2 != de[3][6])
				{
					int temp3 = de[3][2];
					int att3 = de[3][0];

					de[3].pop_front();
					de[3].push_back(att3);

					if(temp3 != de[4][6])
					{
						int att4 = de[4][7];
						de[4].pop_back();
						de[4].push_front(att4);
					}
				}
			}
		}

		//��Ϲ����� 3�ΰ��
		else if(topni_num == 3)
		{
			//�ð� �ݴ������ ���
			if(way == -1)
			{
				int temp3_1 = de[3][6];
				int temp3_2 = de[3][2];

				int att3 = de[3][0];

				de[3].pop_front();
				de[3].push_back(att3);

				if(temp3_2 != de[4][6])
				{
					int att4 = de[4][7];

					de[4].pop_back();
					de[4].push_front(att4);
				}

				if(temp3_1 != de[2][2])
				{
					int temp2 = de[2][6];
					int att2 = de[2][7];

					de[2].pop_back();
					de[2].push_front(att2);

					if(temp2 != de[1][2])
					{
						int att1 = de[1][0];
						de[1].pop_front();
						de[1].push_back(att1);
					}
				}
			}

			//�ð������ ���
			else
			{
				int temp3_1 = de[3][6];
				int temp3_2 = de[3][2];

				int att3 = de[3][7];

				de[3].pop_back();
				de[3].push_front(att3);

				if(temp3_2 != de[4][6])
				{
					int att4 = de[4][0];

					de[4].pop_front();
					de[4].push_back(att4);
				}

				if(temp3_1 != de[2][2])
				{
					int temp2 = de[2][6];
					int att2 = de[2][0];

					de[2].pop_front();
					de[2].push_back(att2);

					if(temp2 != de[1][2])
					{
						int att1 = de[1][7];
						de[1].pop_back();
						de[1].push_front(att1);
					}
				}
			}
		}

		//��Ϲ����� 4�ΰ��
		else if(topni_num == 4)
		{
			//�ð� �ݴ������ ���
			if(way == -1)
			{
				int temp4 = de[4][6];
				int att4 = de[4][0];

				de[4].pop_front();
				de[4].push_back(att4);

				if(temp4 != de[3][2])
				{
					int temp3 = de[3][6];
					int att3 = de[3][7];

					de[3].pop_back();
					de[3].push_front(att3);

					if(temp3 != de[2][2])
					{
						int temp2 = de[2][6];
						int att2 = de[2][0];

						de[2].pop_front();
						de[2].push_back(att2);

						if(temp2 != de[1][2])
						{
							int att1 = de[1][7];
							de[1].pop_back();
							de[1].push_front(att1);
						}
					}
				}
			}

			//4�̰� �ð� ������ ���
			else
			{
				int temp4 = de[4][6];
				int att4 = de[4][7];

				de[4].pop_back();
				de[4].push_front(att4);

				if(temp4 != de[3][2])
				{
					int temp3 = de[3][6];
					int att3 = de[3][0];

					de[3].pop_front();
					de[3].push_back(att3);

					if(temp3 != de[2][2])
					{
						int temp2 = de[2][6];
						int att2 = de[2][7];

						de[2].pop_back();
						de[2].push_front(att2);

						if(temp2 != de[1][2])
						{
							int att1 = de[1][0];
							de[1].pop_front();
							de[1].push_back(att1);
						}
					}
				}
			}
		}
	}

	int total = 0;
	for(int i = 1; i <= 4; i++)
	{
		if(de[i][0] == 1)
		{
			total += pow(2,(i-1));
		}
	}

	printf("%d\n",total);
	return 0;
}