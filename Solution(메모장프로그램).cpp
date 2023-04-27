#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int h, w;
list<char> words;
list<char>::iterator cursor;

void init(int H, int W, char mStr[]) {
	// H : 메모장 높이, W : 메모장 너비, mStr : 최초 문자열
	// 최초 커서 위치는 첫번째 문자열 왼쪽 (0번 인덱스)
	h = H; w = W;
	for (int i = 0; i < strlen(mStr); i++) {
		words.push_back(mStr[i]);
	}
	cursor = words.begin();
}

void insert(char mChar) {
	// 현재 커서 위치에 mChar을 삽입
	words.insert(cursor, mChar);
}

char moveCursor(int mRow, int mCol) {
	// mRow행 mCol열 문자의 왼쪽으로 커서를 이동
	// 커서의 다음 문자나, 마지막 문자일 경우 $를 반환
	// mRow행 : i
	// mCol열 : j
	cursor = words.begin();
	int pos = (mRow - 1) * w + (mCol - 1);
	for (int i = 0; i < pos; i++) {
		cursor++;
		if (cursor == words.end()) {
			return '$';
		}
	}
	return *cursor;
}

int countCharacter(char mChar) {
	// 커서 뒤쪽 문자열에서 mChar문자의 갯수를 반환
	int cnt = 0;
	for (cursor; cursor != words.end(); cursor++) {
		if (*cursor == mChar) {
			cnt++;
		}
	}

	return cnt;
}