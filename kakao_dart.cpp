#include<iostream>
#include<string>

using namespace std;

int main()
{
	//�Է�
	string dart_result;

	cin >> dart_result;

	//���ڿ� ����
	int length = dart_result.size();

	//���� ����
	int stage[3];
	int score[3];
	int option[3];

	bool isoption = false;

	int point = 0;
	int index = 0;

	//���ڿ� ������
	for(int i = 0; i < length; i++)
	{
		if(dart_result[i] == 'S' || dart_result[i] == 'D' || dart_result[i] == 'T')
		{
			//���� �������� ���ϱ�(s = 1���� d = 2���� d = 3����)
			if(dart_result[i] == 'S')
			{
				stage[index] = 1;
			}

			else if(dart_result[i] == 'D')
			{
				stage[index] = 2;
			}

			else if(dart_result[i] == 'T')
			{
				stage[index] = 3;
			}

			//���� ���� ���ϱ�
			score[index] = stoi(dart_result.substr(point, i - point));

			//�ɼ� �޺� ���ϱ�(*,#)
			if(dart_result[i+1] == '*')
			{
				option[index] = 1;
				isoption = true;
			}
			else if(dart_result[i+1] == '#')
			{
				option[index] = 2;
				isoption = true;
			}
			else
			{
				option[index] = 0;
				isoption = false;
			}

			//���� �������� �غ�
			index ++;

			if(isoption)
			{
				point = i + 2;
			}
			else
			{
				point = i + 1;
			}
		}
	}

	int total[3];

	//���� ���
	for(int i = 0; i < 3; i++)
	{
		if(i == 0)
		{
			total[i] = pow(score[i],stage[i]);

			if(option[i] == 1)
			{
				total[i] *= 2;
			}
			else if(option[i] == 2)
			{
				total[i] *= -1;
			}
		}

		else
		{
			total[i] = pow(score[i],stage[i]);
			if(option[i] == 1)
			{
				total[i] *= 2;
				total[i-1] *= 2;
			}
			else if(option[i] == 2)
			{
				total[i] *= -1;
			}
		}
	}

	//��� ���
	int ans = 0;

	for(int i = 0; i < 3; i++)
	{
		ans += total[i];
	}

	cout << ans << '\n';

	return 0;
}