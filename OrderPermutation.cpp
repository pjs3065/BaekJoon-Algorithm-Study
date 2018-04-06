#include<stdio.h>
#include<stdlib.h>

void swap(int *set, int a, int b);
void print(int *set, int n);

int main(void)
{
	int n, c, count = 0;
	int *set;
	int i, j;

	//�Է� ī��Ʈ
	scanf("%d",&n);

	//���̳��� �Ҵ�
	set = (int*)malloc(sizeof(int) * n);

	//�ɼ� ����
	scanf("%d",&c);

	//������ 1�̸�
	if(c == 1)
	{
		scanf("%d",&count);
		count = count -1;

		//�Է� ����
		for(i = 0; i < n; i++)
		{
			set[i] = i + 1;
		}

		while (count--)
		{
			//���� ū i�� �ֱ�
			i = n - 1;

			//i�� 0���� ũ��  i-1�� i���� ũ�ų� ���� �� i�� ����
			while(i > 0 && (set[i-1] >= set[i])) i--;

			//���� i�� 0�̸� -1�� ���
			if(i == 0)
			{
				return 0;
			}

			//���� ū j�� �ֱ�
			j = n - 1;

			//j�� i���� ũ�ų� ���� i-1�� ������ j�� ���� ������ ū���� ã�� ���ؼ� j�� ������ �̵�
			while(j >= i && set[j] <= set[i-1]) j--;

			//ū���� ã���� swap
			swap(set,i-1,j);

			//���� ū j�� �ٽ� �ʱ�ȭ
			j = n - 1;

			//i�����ȿ��� �ִ� ��� �� swap�ϱ�
			while( i < j )
			{
				swap(set,i,j);
				i++;
				j--;
			}
		}

		//set ���
		print(set,n);
	}

	else if(c == 2)
	{
		for(i = 0; i < n; i++)
		{
			scanf("%d", &set[i]);
		}

		while (1)
		{
			//���� ū i�� �ֱ�
			i = n - 1;

			//i�� 0���� ũ��  i-1�� i���� �۰ų� ���� �� i�� ����
			while(i > 0 && (set[i-1] <= set[i])) i--;

			//���� i�� 0�̸� -1�� ���
			if(i == 0)
			{
				printf("%d\n",count + 1);
				return 0;
			}

			count ++;

			//���� ū j�� �ֱ�
			j = n - 1;

			//j�� i���� ũ�ų� ���� i-1�� ������ j�� ���� ũ�ų� ������ ���� ���� ã�� ���ؼ� j�� ������ �̵�
			while(j >= i && set[j] >= set[i-1]) j--;

			//ū���� ã���� swap
			swap(set,i-1,j);

			//���� ū j�� �ٽ� �ʱ�ȭ
			j = n - 1;

			//i�����ȿ��� �ִ� ��� �� swap�ϱ�
			while( i < j )
			{
				swap(set,i,j);
				i++;
				j--;
			}
		}
	}
	return 0;
}

/*
purpose : swap set[a], set[b]
input : *set, a, b
ouput : none
*/
void swap(int *set, int a, int b)
{
	int temp;

	temp = set[a];
	set[a] = set[b];
	set[b] = temp;
}

void print(int *set, int n)
{
	//�Է� ���
	for(int i = 0; i < n; i++)
	{
		printf("%d ",set[i]);
	}
	printf("\n");
}