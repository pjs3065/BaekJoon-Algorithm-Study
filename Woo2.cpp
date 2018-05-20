#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int solution(string &A, string &B);

int main()
{
	string a, b;
	cin >> a >> b;

	solution(a,b);

	return 0;
}

int solution(string &A, string &B) {

	int length = A.length();
	int alex = 0;

	for(int i = 0; i < length; i++)
	{
		int a = 0;
		int b = 0;

		printf("%d %d\n", A[i],B[i]);

		if(A[i] >= 'A' && A[i] <= 'Z')
		{
			switch(A[i])
			{
			case 'A' : a = 14; break;
			case 'K' : a = 13; break;
			case 'Q' : a = 12; break;
			case 'J' : a = 11; break;
			case 'T' : a = 10; break;
			}
		}

		else if(A[i] >= '2' && A[i] <= '9')
		{
			a = A[i]-'0';
		}

		if(B[i] >= 'A' && B[i] <= 'Z')
		{
			switch(B[i])
			{
			case 'A' : b = 14; break;
			case 'K' : b = 13; break;
			case 'Q' : b = 12; break;
			case 'J' : b = 11; break;
			case 'T' : b = 10; break;
			}
		}

		else if(B[i] >= '2' && B[i] <= '9')
		{
			b = B[i]-'0';
		}

		printf("\n");
		printf("%d %d\n", a,b);


		if(a > b)
		{
			alex ++;
		}

	}
	return alex;
}