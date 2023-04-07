#include <iostream>
#include <algorithm>

using namespace std;

int ans = 0;
int N;
//N이 최대 15라서 15크기 배열 생성
int board[15][15];
int col[15];
int row[15];

bool is_promising(int i, int j) {
	for (int ii = 0; ii < i; ii++) {
		if ((abs(col[ii] - j)) == (abs(ii - i)) && board[ii][col[ii]] == 1) {
			return false;
		}
	}
	return true;
}

void backtracking(int i) {
	if (i == N) {
		ans += 1;
		return;
	}

	for (int j = 0; j < N; j++) {
		if (row[j]==0){
			if (is_promising(i, j)) {
				row[j] = 1;
				col[i] = j;
				board[i][j] = 1;
				backtracking(i + 1);
				row[j] = 0;
				col[i] = 0;
				board[i][j] = 0;
			}
		}
	}
}

int main() {

	cin >> N;

	backtracking(0);
	cout << ans << endl;

	return 0;
}