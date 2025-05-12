#include<iostream>
#include <cstdio>
#include <string>
using namespace std;


/*
369게임

369 는 '-'로 표시
369가 들어간 숫자만큼 '-'
만얄 36 이면 '--'


*/
int main(int argc, char** argv)
{

	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//FILE* fp;
	//freopen_s(&fp, "input.txt", "r", stdin);
	cin >> T;

	string str;
	for (int i = 1; i <= T; i++)
	{
		if (i != 1) { cout << " "; }
		str = to_string(i);
		int count = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '3' || str[j] == '6' || str[j] == '9')
			{
				count++;
			}
		}

		if (count != 0)
		{
			for (int j = 0; j < count; j++)
			{
				cout << '-';
			}
		}
		else {
			cout << i;
		}

	}



	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}