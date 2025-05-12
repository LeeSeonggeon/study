#include<iostream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	double sum;
	int count = 10;
	double result;
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
		int temp;
		sum = 0;
		for (int i = 0; i < count; i++)
		{
			cin >> temp;
			sum += temp;
		}
		
		result = sum / count;
		double temp2 = result - (int)result;
		if (temp2 >= 0.5)
		{
			result = (int)result + 1;
		}
		else
		{
			result = (int)result;
		}
		/*
		//위의 방식은 부동소수점 오차로 인해 문제가 생길 수 도 있다.
		//직접 짜야 한다면 다음과 같이
		result = result +0.5
		result = (int)result;
		//반올림을 해주는 함수가 이미 있음. 이를 사용하면
		result = round(result);
		
		*/

		cout << "#" << test_case << " " << result << endl;
	}

	if (fp != nullptr)
	{
		fclose(fp);
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}