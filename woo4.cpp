#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int solution(int A, int B, int C, int D);

int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;

	int ans = solution(a,b,c,d);
	cout << ans << '\n';

	return 0;
}

int solution(int A, int B, int C, int D) {

	vector<int> option;

	option.push_back(A);
	option.push_back(B);
	option.push_back(C);
	option.push_back(D);

	sort(option.begin(), option.end());

	int max_distance = -1;

	do
	{

		printf("%d %d %d %d\n",option[0], option[1], option[2], option[3]);
		int distance = ((option[0]-option[1]) * (option[0]-option[1])) + ((option[2]-option[3]) * (option[2]-option[3]));

		if(max_distance < distance)
		{
			max_distance = distance;
		}

	}while(next_permutation(option.begin(),option.end())); 

	return max_distance;
}