#include<stdio.h>
#include<vector>

using namespace std;

int main()
{
	int n, d, k, j;
	scanf("%d %d %d %d", &n, &d, &k, &j);

	//��ü �ο���
	int count = n-1; // 6���Ͻ� 5�� Ż�� ��Ű�� ����

	//����� �� ����� Ż�� ����
	vector<int> man (n + 1);
	vector<int> check (n + 1);

	//�ð������ ���
	if(d == 1)
	{
		int start = 0;
		int p = 1;

		while(count != 0)
		{
			int next = k;

			//ù ����
			if(start == 0)
			{
				start = 1;
				p = p + k;

				if(p > n)
				{
					p = (p % n);
				}

				check[p] = 1; //Ż��
				count--;
			}

			// ó�� ���� ������
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

				//�ش� ������ ã�� Ż����Ű��
				check[p] = 1;

				//���� �ִ� �ο� ����
				count --;
			}

			//k�� j ��ŭ ����
			k = k + j;
		}
	}

	//�ð� �ݴ� ������ ���
	else if (d == 0)
	{
		int start = 0;
		int p = 1;

		while(count != 0)
		{
			int next = k;

			//ù ����
			if(start == 0)
			{
				start = 1;
				p = p - k;

				if(p < 1)
				{
					p = p + n;
				}

				check[p] = 1; //Ż��
				count--;
			}

			// ó�� ���� ������
			else
			{
				//���� ������ �� ��
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

				//�ش� ������ ã�� Ż����Ű��
				check[p] = 1;

				//���� �ִ� �ο� ����
				count --;
			}
			//k�� j��ŭ ��� 
			k = k + j;
		}
	}

	//��� �� ���
	for(int i = 1; i <= n; i++)
	{
		if(check[i] == 0)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}