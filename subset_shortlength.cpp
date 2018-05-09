#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, s;
	int sum = 0;
	int left = 0, right = 0;
	int min_length = 1000001;

	//�Է�
	scanf("%d %d",&n, &s);

	vector<int> subset(n);

	//�κ��� �Է�
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&subset[i]);
	}

	sum = subset[left] + subset[right];

	while(1)
	{
		//���ǰ� ���� ���� ���
		if(s == sum)
		{
			cout << "dd" << right << ' ' << left << '\n';
			//�ּҰ� ���̿� �־��ش�
			if(min_length > right - left)
			{
				min_length = right - left;
			}

			//���������� �̵��ϰ� �ϰ�
			right ++;

			//�������� n���� ũ�ų� ������ ��
			if(right >= n)
			{
				break;
			}

			//�ƴϸ� �̵��� ������ subset�� ���Ѵ�.
			else
			{
				sum += subset[right];
			}
		}

		//���Ǻ��� ���� ���� ���
		else if(s > sum)
		{
			//���������� �̵���Ű��
			right++;

			//�� ���ǰ� �����ϴ�
			if(right >= n)
			{
				break;
			}

			else
			{
				sum += subset[right];
			}
		}

		//���Ǻ��� ���� Ŭ ���
		else if(s < sum)
		{
			//���� left�� right�� ������ Ȯ������ ������
			if(left == right)
			{
				//���� ���ǰ� �����ϰ� �����̸�
				right ++;

				if(right >= n)
				{
					break;
				}

				else
				{
					sum += subset[right];
				}
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
	if(min_length ==  1000001)
	{
		min_length = 0;
	}

	//���
	printf("%d\n",min_length);

	return 0;
}