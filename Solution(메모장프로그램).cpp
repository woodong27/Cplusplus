#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int h, w;
list<char> words;
list<char>::iterator cursor;

void init(int H, int W, char mStr[]) {
	// H : �޸��� ����, W : �޸��� �ʺ�, mStr : ���� ���ڿ�
	// ���� Ŀ�� ��ġ�� ù��° ���ڿ� ���� (0�� �ε���)
	h = H; w = W;
	for (int i = 0; i < strlen(mStr); i++) {
		words.push_back(mStr[i]);
	}
	cursor = words.begin();
}

void insert(char mChar) {
	// ���� Ŀ�� ��ġ�� mChar�� ����
	words.insert(cursor, mChar);
}

char moveCursor(int mRow, int mCol) {
	// mRow�� mCol�� ������ �������� Ŀ���� �̵�
	// Ŀ���� ���� ���ڳ�, ������ ������ ��� $�� ��ȯ
	// mRow�� : i
	// mCol�� : j
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
	// Ŀ�� ���� ���ڿ����� mChar������ ������ ��ȯ
	int cnt = 0;
	for (cursor; cursor != words.end(); cursor++) {
		if (*cursor == mChar) {
			cnt++;
		}
	}

	return cnt;
}