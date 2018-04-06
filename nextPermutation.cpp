#include<stdio.h>
#include<stdlib.h>

void swap(int *set, int a, int b);

int main(void)
{
	int n;
	int *set;
	int i, j;

	//입력 카운트
	scanf("%d",&n);

	//다이나믹 할당
	set = (int*)malloc(sizeof(int) * n);

	//입력 집합
	for(i = 0; i < n; i++)
	{
		scanf("%d",&set[i]);
	}

	//제일 큰 i값 넣기
	i = n - 1;

	//i가 0보다 크고  i-1이 i보다 크거나 같을 때 i값 감소
	while(i > 0 && (set[i-1] >= set[i])) i--;

	//만약 i가 0이면 -1을 출력
	if(i == 0)
	{
		printf("-1\n");
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

	//set 출력
	for(i = 0; i < n; i++)
	{
		printf("%d ",set[i]);
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