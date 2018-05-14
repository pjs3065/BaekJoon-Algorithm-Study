#include<iostream>
#include<string>

using namespace std;

int main()
{
	//입력
	string dart_result;

	cin >> dart_result;

	//문자열 길이
	int length = dart_result.size();

	//게임 변수
	int stage[3];
	int score[3];
	int option[3];

	bool isoption = false;

	int point = 0;
	int index = 0;

	//문자열 나누기
	for(int i = 0; i < length; i++)
	{
		if(dart_result[i] == 'S' || dart_result[i] == 'D' || dart_result[i] == 'T')
		{
			//게임 스테이지 정하기(s = 1제곱 d = 2제곱 d = 3제곱)
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

			//게임 점수 정하기
			score[index] = stoi(dart_result.substr(point, i - point));

			//옵션 콤보 정하기(*,#)
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

			//다음 스테이지 준비
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

	//점수 계산
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

	//답안 출력
	int ans = 0;

	for(int i = 0; i < 3; i++)
	{
		ans += total[i];
	}

	cout << ans << '\n';

	return 0;
}