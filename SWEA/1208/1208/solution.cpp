#include<iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
한쪽 벽에 노란 박스가 쌓여 있음

박스의 높이 차이를 줄이는 평탄화 작업을 수행하려 한다.
평탄화 작업을 모두 수행하면, max와 min의 차이가 최대 1이 된다.

평탄화 작업의 옮기는 횟수가 제한이 걸려있음
제한된 횟수만큼 옮겼을 때 max-min을 반환하는 프로그램

가로 길이는 항상 100
상자의 높이는 1이상 100이하
옮기기 횟수는 1이상 1000이하
옮기기 횟수 모두 소진시 max-min 반환

입력:
총 10개의 테스트 케이스가 주어짐
1. 옮기기 횟수
2. 각 위치의 상자 높이값

출력:
#test_case max-min


*/

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	int dump_count;
	int arr[100];
	
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
	//cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> dump_count;
		for (int i = 0; i < 100; i++)
		{
			cin >> arr[i];
		}
		
		for (int i = 0; i < dump_count; i++)
		{
			sort(arr, arr + 100);	//정렬 진행
			if (arr[99] - arr[0] <= 1)
			{
				break;
			}
			arr[0] += 1;
			arr[99] -= 1;
		}
		sort(arr, arr + 100);	//정렬 진행
		cout << "#" << test_case << " " << arr[99] - arr[0] << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}