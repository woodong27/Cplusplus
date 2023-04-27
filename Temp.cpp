#include <iostream>
#include <bitset>
#include <list>

using namespace std;

int main() {

	list<char> words;
	list<char>::iterator cursor;

	words.push_back('b');
	words.push_back('c');
	words.push_back('d');
	words.push_back('e');
	words.push_back('g');

	cursor = words.begin();
	 
	int cnt = 0;
	for (cursor; cursor != words.end(); cursor++) {
		if (*cursor == 'b') {
			cnt++;
		}
	}
	cout << cnt << endl;

	cursor = words.begin();
	int pos = 1 * 4 + 0;
	for (int i = 0; i < pos; i++) {
		cursor++;
	}

	cout << *cursor << endl;

	words.insert(cursor, 'f');

	cursor = words.begin();
	pos = 0 * 4 + 3;
	for (int i = 0; i < pos; i++) {
		cursor++;
	}

	cout << *cursor << endl;

	cnt = 0;
	for (cursor; cursor != words.end(); cursor++) {
		if (*cursor == 'f') {
			cnt++;
		}
	}
	cout << cnt << endl;

	cursor = words.begin();
	pos = 1 * 4 + 3;
	for (int i = 0; i < pos; i++) {
		cursor++;
		if (cursor == words.end()) {
			cout << '$' << endl;
			break;
		}
		else if (i == pos - 1) {
			cout << *cursor << endl;
		}
	}

	words.insert(cursor, 'e');
	words.insert(cursor, 'b');

	cnt = 0;
	for (cursor; cursor != words.end(); cursor++) {
		if (*cursor == 'b') {
			cnt++;
		}
	}
	cout << cnt << endl;

	cursor = words.begin();
	pos = 2 * 4 + 0;
	for (int i = 0; i < pos; i++) {
		cursor++;
		if (cursor == words.end()) {
			cout << '$' << endl;
			break;
		}
		else if (i == pos - 1) {
			cout << *cursor << endl;
		}
	}



	return 0;
}