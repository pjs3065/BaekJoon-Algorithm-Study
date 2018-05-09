#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, s;
	int sum = 0;
	int left = 0, right = 0;
	int min_length = 1000002;

	//�Է�
	scanf("%d %d",&n, &s);

	vector<int> subset(n + 1);

	//�κ��� �Է�
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&subset[i]);
	}

	sum = subset[0];

	while(right < n)
	{
		//���ǰ� ���� ���� ���
		if(s == sum)
		{
			//�ּҰ� ���̿� �־��ش�
			if(min_length > right - left)
			{
				min_length = right - left + 1;
			}

			//���������� �̵��ϰ� �ϰ�
			right ++;
			sum += subset[right];
		}

		//���Ǻ��� ���� ���� ���
		else if(s > sum)
		{
			//���������� �̵���Ű��
			right++;
			sum += subset[right];
		}

		//���Ǻ��� ���� Ŭ ���
		else if(s < sum)
		{
			//�ּҰ� ���̿� �־��ش�
			if(min_length > right - left)
			{
				min_length = right - left + 1;
			}

			//���� left�� right�� ������ Ȯ������ ������
			if(left == right)
			{
				//���� ���ǰ� �����ϰ� �����̸�
				right ++;
				sum += subset[right];
			}

			//�ƴ� ��쿡��
			else 
			{
				//������ �Ű� ������ �հ迡�� ���ְ� �������� �Ű��ش�. ������ ������.
				sum -= subset[left];
				left ++;
			}
		}
	}

	//min_length�� �״���� ��� 0���� ��ȯ
	if(min_length ==  1000002)
	{
		min_length = 0;
	}

	//���
	printf("%d\n",min_length);

	return 0;
}