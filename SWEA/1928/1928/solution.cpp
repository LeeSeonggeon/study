#include<iostream>
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

/*

A~Z : 0~25
a~z : 26~51
0~9 : 52~61
+ : 62
/ : 63
*/
unordered_map<char, int> Alpha = {
	{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9}, {'K', 10}, {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19}, {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24}, {'Z', 25},
	{'a', 26}, {'b', 27}, {'c', 28}, {'d', 29}, {'e', 30}, {'f', 31}, {'g', 32}, {'h', 33}, {'i', 34}, {'j', 35}, {'k', 36}, {'l', 37}, {'m', 38}, {'n', 39}, {'o', 40}, {'p', 41}, {'q', 42}, {'r', 43}, {'s', 44}, {'t', 45}, {'u', 46}, {'v', 47}, {'w', 48}, {'x', 49}, {'y', 50}, {'z', 51},
	{'0' , 52}, {'1' , 53}, {'2' , 54}, {'3' , 55}, {'4' , 56}, {'5' , 57}, {'6' , 58}, {'7' , 59}, {'8', 60}, {'9', 61},
	{'+', 62}, {'/', 63}
};

string DecToBinary(int num)
{
	string binary = "";
	while (num > 0)
	{
		binary = to_string(num % 2) + binary;
		num = num / 2;
	}

	if (binary.length() < 6)
	{
		int temp = binary.length();
		for (int i = 0; i < 6 - temp; i++)
		{
			binary = "0" + binary;
		}
	}
	return binary;
}

int BinaryToDec(string str)
{
	int Dec = 0;
	for (int i = 0; i < 8; i++)
	{
		if (str[i] == '1')
		{
			Dec += 1 << (7 - i);
		}
	}
	return Dec;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	string str;
	int* arr;
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
		string result = "";
		cin >> str;
		arr = new int[str.length()];
		//cout << str << endl;
		for (int i = 0; i < str.length(); i++)
		{
			arr[i] = Alpha[str[i]];
			//cout << arr[i] <<" ";
		}
		//cout << endl;
		//cout << "str 길이: " << str.length()<< " " << str.length() / 4 << endl;
		for (int i = 0; i < str.length(); i = i + 4)	//4개를 묶어서 3개의 문자로 바꿈
		{
			//cout << i << " ";
			string temp = "";
			// 0 1 2 3
			// 4 5 6 7
			// 8 9 10 11
			for (int j = 0; j < 4; j++)
			{
				temp += DecToBinary(arr[i + j]);
			}
			// 0~7 / 8~15 / 16~24	, 문자 3개로 나누기
			string char1 = temp.substr(0, 8);
			string char2 = temp.substr(8, 8);
			string char3 = temp.substr(16, 8);
			//cout << char1 << " " << char2 << " " << char3 << endl;

			int c1 = BinaryToDec(char1);
			int c2 = BinaryToDec(char2);
			int c3 = BinaryToDec(char3);
			
			result += static_cast<char>(c1);
			result += static_cast<char>(c2);
			result += static_cast<char>(c3);
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}