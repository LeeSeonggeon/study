#include<iostream>
#include <cstdio>
#include <string>
using namespace std;

enum month {
	JAN = 31,

};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	string YMD;

	//어차피 고정 값인데 동적으로 생성할 필요는 없었을 듯
	int* arr = new int[12];
	arr[0] = 31;
	arr[1] = 28;
	arr[2] = 31;
	arr[3] = 30; 
	arr[4] = 31;
	arr[5] = 30; 
	arr[6] = 31;
	arr[7] = 31;
	arr[8] = 30;
	arr[9] = 31;
	arr[10] = 30;
	arr[11] = 31; 
	

	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> YMD;
		int M = 0;
		int D = 0;

		string temp = "";
		for (int i = 4; i < 6; i++)
		{
			temp += YMD[i];
		}
		M = stoi(temp);

		temp = "";
		for (int i = 6; i < YMD.length(); i++)
		{
			temp += YMD[i];
		}
		D = stoi(temp);

		if (arr[M - 1] < D)
		{
			cout << "#" << test_case << " -1"  << endl;
		}
		else
		{
			
			YMD.insert(4, "/");
			YMD.insert(7, "/");

			cout << "#" << test_case << " " << YMD << endl;
			
		}


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}