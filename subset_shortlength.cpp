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

	//입력
	scanf("%d %d",&n, &s);

	vector<int> subset(n + 1);

	//부분합 입력
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&subset[i]);
	}

	sum = subset[0];

	while(right < n)
	{
		//조건과 합이 같을 경우
		if(s == sum)
		{
			//최소값 길이에 넣어준다
			if(min_length > right - left)
			{
				min_length = right - left + 1;
			}

			//오른쪽으로 이동하게 하고
			right ++;
			sum += subset[right];
		}

		//조건보다 합이 작을 경우
		else if(s > sum)
		{
			//오른쪽으로 이동시키고
			right++;
			sum += subset[right];
		}

		//조건보다 합이 클 경우
		else if(s < sum)
		{
			//최소값 길이에 넣어준다
			if(min_length > right - left)
			{
				min_length = right - left + 1;
			}

			//먼저 left와 right가 같은지 확인한후 같으면
			if(left == right)
			{
				//위의 조건과 동일하게 움직이며
				right ++;
				sum += subset[right];
			}

			//아닐 경우에는
			else 
			{
				//왼쪽을 옮겨 가기전 합계에서 빼주고 왼쪽으로 옮겨준다. 범위를 좁힌다.
				sum -= subset[left];
				left ++;
			}
		}
	}

	//min_length가 그대로일 경우 0으로 변환
	if(min_length ==  1000002)
	{
		min_length = 0;
	}

	//출력
	printf("%d\n",min_length);

	return 0;
}