#include<iostream>
#include<string>

using namespace std;

int main()
{
	int number_i;
	string number_s;

	cin >> number_i;

	//convert integer to string
	if(number_i < 10)
	{
		number_s = "0" + to_string(number_i);
	}
	else
	{
		number_s = to_string(number_i);
	}

	int count = 0;

	int new_number_i = 0;
	string new_number_s  = number_s;

	//creat new number
	do{
		int new_number = ((new_number_s[0] - '0') + (new_number_s[1] - '0')) % 10;
		new_number_s = new_number_s[1] + to_string(new_number);
		count ++;
	}while(new_number_s.compare(number_s));

	int ans = count;
	printf("%d\n", ans);

	return 0;
}