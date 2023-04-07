#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ans = 0;
int N;
//NxN크기의 board 생성
vector<vector<int>>board(N, vector<int>(N, 0));
vector<int>row(N, 0);
vector<int>col(N, 0);

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