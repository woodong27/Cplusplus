#include <iostream>
#include <algorithm>
#include <list>
#include <deque>

using namespace std;

int h, w;
deque<char> words[300];
int ci, cj;

void init(int H, int W, char mStr[]) {
	// H : 메모장 높이, W : 메모장 너비, mStr : 최초 문자열
	// 최초 커서 위치는 첫번째 문자열 왼쪽 (0번 인덱스)
	h = H; w = W;
	
	int i = 0;
	for (int j = 0; j < strlen(mStr); j++) {
		words[i].push_back(mStr[j]);
		if (words[i].size() == w) {
			i++;
		}
	}
	
	ci = 0; cj = 0;
}

void insert(char mChar) {
	// 현재 커서 위치에 mChar을 삽입
	if (words[ci][cj]) {
		
	}

	words[ci].insert(words[ci].begin()+cj, mChar);
	/*
		int temp = ci;
	while (words[temp].size() > w) {
		char last = words[temp].back();
		words[temp].pop_back();
		words[temp + 1].push_front(last);
		temp++;
	}
	*/

}

char moveCursor(int mRow, int mCol) {
	// mRow행 mCol열 문자의 왼쪽으로 커서를 이동
	// 커서의 다음 문자나, 마지막 문자일 경우 $를 반환
	// mRow행 : i
	// mCol열 : j
	ci = mRow - 1;
	cj = mCol - 1;

	return '$';
}

int countCharacter(char mChar) {
	// 커서 뒤쪽 문자열에서 mChar문자의 갯수를 반환


	return 0;
}