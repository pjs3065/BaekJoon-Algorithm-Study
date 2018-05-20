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
	//답이 이미 나왔을 경우 끝
	if(check == true)
	{
		return;
	}

	//무게를 넘어 버리면 백 트레킹
	if(sum > kg)
	{
		return;
	}

	//답이 나온 경우 출력
	if(sum == kg)
	{
		for(int i = 0; i < n; i++)
		{
			printf("%d %d\n",index[i], usage[index[i]]);
		}

		check = true;
		return;
	}

	//계산하기
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

		//백트레킹
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

		//추 무게 구하기 함수
		cal(0);

		//정답이 없을 경우 출력
		if(check == false)
		{
			printf("FAIL\n");
		}

		count++;
	}

	return 0;
}