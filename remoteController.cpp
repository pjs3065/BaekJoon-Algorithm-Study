#include<iostream>
using namespace std;

bool btn[10] = {false,};
int possible(int possible_chanel);

int main()
{
	//입력변수
	int chanel;
	int error_btn_number;
	int cur_chanel = 100;
	
	//연산변수
	int possible_chanel;
	int min_push;
	int push_number;
	int up_down_number;

	//채널과 에러 버튼 갯수를 입력
	cin >> chanel;
	cin >> error_btn_number;

	//고장난 버튼을 입력한다. btn이 true일때 고장난 것으로
	for(int i = 0 ; i < error_btn_number; i++)
	{
		int error_btn;
		cin >> error_btn;
		btn[error_btn] = true; 
	}

	//그냥 + - 눌렀을 때의 최소값 구하기
	min_push = 100 - chanel;
	if(min_push < 0)
	{
		min_push = -min_push;
	}

	//그외의 경우 구하기
	//채널 가능한지 여부 확인하며 최소값 구하기
	for(int i = 0; i <=1000000; i++)
	{
		possible_chanel = i;
		push_number = possible(possible_chanel);

		//모두 누름이 가능한 경우
		if(push_number > 0)
		{
			//원하는 채널보다 아래인 경우 +를 누르는 횟수로
			up_down_number = chanel - i;
			
			//원하는 채널보다 위인 경우 -를 누르는 횟수로
			if(up_down_number < 0)
			{
				up_down_number = -up_down_number;
			}

			//누르는 횟수의 최소값을 할당한다
			if(min_push > up_down_number + push_number)
			{
				min_push = up_down_number + push_number;
			}
		}
	}

	cout <<  min_push << '\n';
	return 0;
}

//possible_chanel이 몇번 누르는거 까지 가능한지 확인
int possible(int possible_chanel)
{
	//0을 눌렀을 때 고장난 경우와 고장나지 않은 경우
	if(possible_chanel == 0)
	{
		if(btn[0])
			return 0;
		else
			return 1;
	}

	int push_number = 0;

	//1이상을 눌렀을 때 고장났을 경우와 고장안났을 경우 
	//(모두 확인하기 때문에 모두다 누르는게 가능할 때 push_number을 리턴한다)
	while(possible_chanel > 0)
	{
		if(btn[possible_chanel % 10])
			return 0;
		else
		{
			push_number += 1;
			possible_chanel /= 10;
		}
	}
	return push_number;
}