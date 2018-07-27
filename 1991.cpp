#include<stdio.h>
#include<vector>

using namespace std;

vector<int> tree[27];

void prefix(char s)
{
	if(s == '.') return;

	printf("%c",s);
	prefix(tree[s-'A'][0]);
	prefix(tree[s-'A'][1]);
}

void infix(char s)
{
	if(s == '.') return;

	infix(tree[s-'A'][0]);
	printf("%c",s);
	infix(tree[s-'A'][1]);
}

void postfix(char s)
{
	if(s == '.') return;

	postfix(tree[s-'A'][0]);	
	postfix(tree[s-'A'][1]);
	printf("%c",s);
}

int main()
{
	int n;
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
	{
		char s, v1, v2;
		scanf(" %c %c %c",&s, &v1, &v2);

		tree[s-'A'].push_back(v1);
		tree[s-'A'].push_back(v2);
	}

	prefix('A');
	printf("\n");

	infix('A');
	printf("\n");
	
	postfix('A');
	printf("\n");

	return 0;
}