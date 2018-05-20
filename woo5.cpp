
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>

using namespace std;

int solution(vector<int> &A, int K, int L);

int main()
{
	vector<int> a;

	a.push_back(6);
	a.push_back(1);
	a.push_back(4);
	a.push_back(6);
	a.push_back(3);
	a.push_back(2);
	a.push_back(7);
	a.push_back(4);

	solution(a, 3, 2);
	return 0;
}

int solution(vector<int> &A, int K, int L) {

	int length = A.size();

	if(K + L > length)
	{
		return -1;
	}

	int alice_p = 0;
	int bob_p = length -1;

	int max = -1;

	while(alice_p + K < length)
	{
		int alice_sum = 0;
		bob_p = length -1;

		vector<int> alice_check(length);

		for(int i = alice_p; i < alice_p + K; i++)
			{
				alice_check[i] = 1;
				alice_sum += A[i];
			}

		while(bob_p - L >= 0)
		{
			int bob_sum = 0;
			int next = 0;

			for(int i = bob_p; i > bob_p - L; i--)
			{
				if(alice_check[i] == 1)
				{
					next = 1;
					break;
				}

				else
				{
					bob_sum += A[i];
				}
			}

			if(next == 1)
			{
				bob_p -= 1;
				continue;
			}

			printf("%d %d\n", bob_sum , alice_sum);

			int total = bob_sum + alice_sum;

			if(max < total)
			{
				max = total;
			}

			bob_p -= 1;
		}

		alice_p += 1;
	}

	int ans = max;

	printf("%d",ans);
}