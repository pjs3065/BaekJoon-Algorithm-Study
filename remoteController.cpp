#include<iostream>
using namespace std;

bool btn[10] = {false,};
int possible(int possible_chanel);

int main()
{
	//�Էº���
	int chanel;
	int error_btn_number;
	int cur_chanel = 100;
	
	//���꺯��
	int possible_chanel;
	int min_push;
	int push_number;
	int up_down_number;

	//ä�ΰ� ���� ��ư ������ �Է�
	cin >> chanel;
	cin >> error_btn_number;

	//���峭 ��ư�� �Է��Ѵ�. btn�� true�϶� ���峭 ������
	for(int i = 0 ; i < error_btn_number; i++)
	{
		int error_btn;
		cin >> error_btn;
		btn[error_btn] = true; 
	}

	//�׳� + - ������ ���� �ּҰ� ���ϱ�
	min_push = 100 - chanel;
	if(min_push < 0)
	{
		min_push = -min_push;
	}

	//�׿��� ��� ���ϱ�
	//ä�� �������� ���� Ȯ���ϸ� �ּҰ� ���ϱ�
	for(int i = 0; i <=1000000; i++)
	{
		possible_chanel = i;
		push_number = possible(possible_chanel);

		//��� ������ ������ ���
		if(push_number > 0)
		{
			//���ϴ� ä�κ��� �Ʒ��� ��� +�� ������ Ƚ����
			up_down_number = chanel - i;
			
			//���ϴ� ä�κ��� ���� ��� -�� ������ Ƚ����
			if(up_down_number < 0)
			{
				up_down_number = -up_down_number;
			}

			//������ Ƚ���� �ּҰ��� �Ҵ��Ѵ�
			if(min_push > up_down_number + push_number)
			{
				min_push = up_down_number + push_number;
			}
		}
	}

	cout <<  min_push << '\n';
	return 0;
}

//possible_chanel�� ��� �����°� ���� �������� Ȯ��
int possible(int possible_chanel)
{
	//0�� ������ �� ���峭 ���� ���峪�� ���� ���
	if(possible_chanel == 0)
	{
		if(btn[0])
			return 0;
		else
			return 1;
	}

	int push_number = 0;

	//1�̻��� ������ �� ���峵�� ���� ����ȳ��� ��� 
	//(��� Ȯ���ϱ� ������ ��δ� �����°� ������ �� push_number�� �����Ѵ�)
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