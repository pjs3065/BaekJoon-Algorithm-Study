#include<stdio.h>
#include<stdlib.h>

void swap(int *set, int a, int b);
void print(int *set, int n);

int main(void)
{
	int n, c, count = 0;
	int *set;
	int i, j;

	//입력 카운트
	scanf("%d",&n);

	//다이나믹 할당
	set = (int*)malloc(sizeof(int) * n);

	//옵션 선택
	scanf("%d",&c);

	//선택이 1이면
	if(c == 1)
	{
		scanf("%d",&count);
		count = count -1;

		//입력 집합
		for(i = 0; i < n; i++)
		{
			set[i] = i + 1;
		}

		while (count--)
		{
			//제일 큰 i값 넣기
			i = n - 1;

			//i가 0보다 크고  i-1이 i보다 크거나 같을 때 i값 감소
			while(i > 0 && (set[i-1] >= set[i])) i--;

			//만약 i가 0이면 -1을 출력
			if(i == 0)
			{
				return 0;
			}

			//제일 큰 j값 넣기
			j = n - 1;

			//j가 i보다 크거나 같고 i-1의 값보다 j의 값이 작으면 큰값을 찾기 위해서 j를 앞으로 이동
			while(j >= i && set[j] <= set[i-1]) j--;

			//큰수를 찾으면 swap
			swap(set,i-1,j);

			//제일 큰 j값 다시 초기화
			j = n - 1;

			//i범위안에서 있는 모든 수 swap하기
			while( i < j )
			{
				swap(set,i,j);
				i++;
				j--;
			}
		}

		//set 출력
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
			//제일 큰 i값 넣기
			i = n - 1;

			//i가 0보다 크고  i-1이 i보다 작거나 같을 때 i값 감소
			while(i > 0 && (set[i-1] <= set[i])) i--;

			//만약 i가 0이면 -1을 출력
			if(i == 0)
			{
				printf("%d\n",count + 1);
				return 0;
			}

			count ++;

			//제일 큰 j값 넣기
			j = n - 1;

			//j가 i보다 크거나 같고 i-1의 값보다 j의 값이 크거나 같으면 작은 값을 찾기 위해서 j를 앞으로 이동
			while(j >= i && set[j] >= set[i-1]) j--;

			//큰수를 찾으면 swap
			swap(set,i-1,j);

			//제일 큰 j값 다시 초기화
			j = n - 1;

			//i범위안에서 있는 모든 수 swap하기
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
	//입력 출력
	for(int i = 0; i < n; i++)
	{
		printf("%d ",set[i]);
	}
	printf("\n");
}