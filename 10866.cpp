#include<cstdio>
#include<cstring>
#include<deque>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	char op[20];

	deque<int> deq;

	while(n--)
	{
		scanf("%s",&op);

		if(!strcmp(op,"push_front"))
		{
			int x;
			scanf("%d", &x);
			deq.push_front(x);
		}
		else if(!strcmp(op,"push_back"))
		{
			int x;
			scanf("%d", &x);
			deq.push_back(x);
		}
		else if(!strcmp(op,"pop_front"))
		{
			if(deq.empty()) printf("-1\n");
			else
			{
				printf("%d\n",deq.front());
				deq.pop_front();
			}
		}
		else if(!strcmp(op,"pop_back"))
		{
			if(deq.empty()) printf("-1\n");
			else
			{
				printf("%d\n",deq.back());
				deq.pop_back();
			}
		}
		else if(!strcmp(op,"size"))
		{
			printf("%d\n",deq.size());
		}
		else if(!strcmp(op,"empty"))
		{
			if(deq.empty()) printf("1\n");
			else printf("0\n");
		}
		else if(!strcmp(op,"front"))
		{
			if(deq.empty()) printf("-1\n");
			else printf("%d\n",deq.front());
		}
		else if(!strcmp(op,"back"))
		{
			if(deq.empty()) printf("-1\n");
			else printf("%d\n",deq.back());
		}
	}

	return 0;
}