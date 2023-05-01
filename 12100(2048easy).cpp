#include <iostream>
#include <algorithm>

using namespace std;

int n;
int board[20][20];
int di[] = { 0,0,-1,1 };
int dj[] = { -1,1,0,0 };
int ans = 0;

void backtrack(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			ans = max(ans, *max_element(board[i], board[i] + n));
		}
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	backtrack(0);

	return 0;
}