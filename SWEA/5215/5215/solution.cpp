#include<iostream>
#include<cstdio>
#include <algorithm>

using namespace std;

/*
재료마다 맛의 점수와 칼로리가 있음 (P, K)
정해진 칼로리 이하의 조합 중에 가장 맛있는 햄버거를 제조
동일 재료 중복 불가

재료의 수 N, 제한 칼로리 L
멋 점수, 칼로리

Time Out
mask의 이용으로 길어짐
순열이 상관 없게 해야함
A -> B를 이미 했는데
B -> A 도 하게 됨
이를 해결해야 함
*/
int Result = 0;	// 맛 점수
int cal = 0;
int answer;	//맛 점수
int N;
int L;
bool* mask;


void DNF(int* P, int* K, int idx)
{
	if (cal > L) return;
	answer = max(answer, Result);
	//칼로리 제한 넘기 전에 종료해야 됨
	//다른 종료 조건이 있는가? 없음
	for (int i =idx+1 ; i< N; i++)
	{
		if (mask[i] == true)// 이미 사용한 값은 제외
		{
			continue;
		}
		//사용하지 않은 값
		mask[i] = true;

		Result += P[i];
		cal += K[i];

		DNF(P, K, i+1);

		Result -= P[i];
		cal -= K[i];

		mask[i] = false;//DNF를 나갈때는 사용하지 않은 것으로 만들어주기
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	int* P;
	int* K;
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
	freopen_s(&fp,"input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		Result = 0;
		cal = 0;
		cin >> N >> L;

		P = new int[N];
		K = new int[N];
		mask = new bool[N]();
		for (int i = 0; i < N; i++)
		{
			cin >> P[i] >> K[i];
		}

		DNF(P, K, -1);

		cout << "#" << test_case << " " << answer << endl;

		delete[] P;
		delete[] K;
		delete[] mask;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


/*
#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int answer;

void DFS(int idx, int taste, int cal, int* P, int* K) {
	if (cal > L) return;

	answer = max(answer, taste);

	for (int i = idx; i < N; i++) {
		DFS(i + 1, taste + P[i], cal + K[i], P, K);
	}
}

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> N >> L;
		int* P = new int[N];
		int* K = new int[N];
		answer = 0;

		for (int i = 0; i < N; i++) {
			cin >> P[i] >> K[i];
		}

		DFS(0, 0, 0, P, K);

		cout << "#" << test_case << " " << answer << endl;

		delete[] P;
		delete[] K;
	}

	return 0;
} 
*/