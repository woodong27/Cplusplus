#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

//지도 nxn, 경사로의 높이=1, 길이=l
int n, l;
int map[100][100];
int ans = 0;

void check_row(int si, int sj) {
	deque<int> temp;
	for (int j = 0; j < n; j++) {
		temp.push_back(map[si][j]);
	}

	for (int i = 0; i < n - l; i++) {
		for (int j = 1; j <= l; j++) {
			if ()
		}
	}
}

void check_col(int si, int sj) {
	deque<int> temp;
	for (int i = 0; i < n; i++) {
		temp.push_back(map[i][sj]);
	}

	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0) {
				check_col(i,j);
			}
			if (j == 0) {
				check_row(i,j);
			}
		}
	}

	return 0;
}