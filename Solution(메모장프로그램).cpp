#include <iostream>
#include <algorithm>
#include <list>
#include <deque>

using namespace std;

int h, w;
deque<char> words[300];
int ci, cj;

void init(int H, int W, char mStr[]) {
	// H : �޸��� ����, W : �޸��� �ʺ�, mStr : ���� ���ڿ�
	// ���� Ŀ�� ��ġ�� ù��° ���ڿ� ���� (0�� �ε���)
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
	// ���� Ŀ�� ��ġ�� mChar�� ����
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
	// mRow�� mCol�� ������ �������� Ŀ���� �̵�
	// Ŀ���� ���� ���ڳ�, ������ ������ ��� $�� ��ȯ
	// mRow�� : i
	// mCol�� : j
	ci = mRow - 1;
	cj = mCol - 1;

	return '$';
}

int countCharacter(char mChar) {
	// Ŀ�� ���� ���ڿ����� mChar������ ������ ��ȯ


	return 0;
}