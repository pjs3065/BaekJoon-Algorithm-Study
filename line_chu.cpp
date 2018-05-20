#include<stdio.h>
#include<algorithm>

using namespace std;

int index[256];
int usage[256];
int capacity[256];

int t;
int kg;
int n;

bool check;

void cal(int sum)
{
	//���� �̹� ������ ��� ��
	if(check == true)
	{
		return;
	}

	//���Ը� �Ѿ� ������ �� Ʈ��ŷ
	if(sum > kg)
	{
		return;
	}

	//���� ���� ��� ���
	if(sum == kg)
	{
		for(int i = 0; i < n; i++)
		{
			printf("%d %d\n",index[i], usage[index[i]]);
		}

		check = true;
		return;
	}

	//����ϱ�
	for(int i = 0; i < n; i++)
	{
		if(capacity[index[i]] > usage[index[i]])
		{
			sum+= index[i];
			usage[index[i]]++;
		}

		else
		{
			continue;
		}

		cal(sum);

		//��Ʈ��ŷ
		sum-= index[i];
		usage[index[i]]--;
	}
}

int main()
{
	int count = 1;

	scanf("%d",&t);

	while(count <= t)
	{
		scanf("%d %d", &kg, &n);

		memset(index,sizeof(index),0);
		memset(usage,sizeof(usage),0);
		memset(capacity,sizeof(capacity),0);

		for(int i = 0; i < n; i++)
		{
			int chu, c;
			scanf("%d %d", &chu, &c);
			index[i] = chu;
			capacity[chu] = c;
		}

		printf("#%d\n", count);

		check = false;

		//�� ���� ���ϱ� �Լ�
		cal(0);

		//������ ���� ��� ���
		if(check == false)
		{
			printf("FAIL\n");
		}

		count++;
	}

	return 0;
}