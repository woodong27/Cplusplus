#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>

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
	cursor = words.begin();
	for (int i = 0; i < mRow * mCol; i++) {
		cursor++;
	}
	if (cursor == words.end()) {
		return '$';
	}
	else {
		return *cursor;
	}
}

int countCharacter(char mChar) {
	// Ŀ�� ���� ���ڿ����� mChar������ ������ ��ȯ
	int cur = 

	return -1;
}
