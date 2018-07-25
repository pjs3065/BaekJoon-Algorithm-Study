#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

int main()
{
	int n, m, v; // n: ���� m: ����, v: ������ ������ ��ȣ
	scanf("%d %d %d", &n, &m, &v);
	vector<int> graph[1001];

	//������ �Է�
	int s,e;
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &s, &e);
		graph[s].push_back(e); graph[e].push_back(s);
	}

	//���� �� ���� ������ �����ϱ�
	for(int i = 0; i < n; i++)
	{
		sort(graph[i].begin(),graph[i].end());
	}

	//dfs �����
	vector<int> check1(1001);

	//stack ����
	stack<int> st;
	st.push(v);
	check1[v] = 1;
	printf("%d ", v);

	while(!st.empty())
	{
		int p = st.top();
		st.pop();

		int len = graph[p].size();

		for(int i = 0; i < len; i++)
		{
			int c_v = graph[p][i];

			if(check1[c_v] == 0)
			{
				st.push(p);
				st.push(c_v);
				check1[c_v] = 1;
				printf("%d ",c_v);
				break;
			}
		}
	}
	printf("\n");

	//bfs �����
	vector<int> check2(1001);

	//ť ���� 
	queue<int> q;
	q.push(v);
	check2[v] = 1;
	printf("%d ",v);

	while(!q.empty())
	{
		int p = q.front();
		q.pop();

		int len = graph[p].size();

		for(int i = 0; i < len; i++)
		{
			int c_v = graph[p][i];

			if(check2[c_v] == 0)
			{
				q.push(c_v);
				check2[c_v] = 1;
				printf("%d ",c_v);
			}
		}
	}
	return 0;
}