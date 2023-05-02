#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n;
int board[20][20];
int copied_board[5][20][20];
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };
int ans = 0;

// 똑같은 수가 세개 있으면 이동하려는 방향의 칸이 먼져 합쳐지게 됨
void moving(int id, int jd) {
	deque<int> temp;

	// 왼쪽으로 이동
	if (jd == -1) {
		for (int i = 0; i < n; i++) {
			temp.clear();
			for (int j = 0; j < n; j++) {
				if (board[i][j]) {
					if (!temp.empty() && temp.back() == board[i][j]) {
						int popped = temp.back();
						temp.pop_back();
						temp.push_back(popped * 2);
					}
					else {
						temp.push_back(board[i][j]);
					}
				}
			}
			while (temp.size() < n) {
				temp.push_back(0);
			}
			for (int j = 0; j < n; j++) {
				board[i][j] = temp[j];
			}
		}
	}

	//오른쪽으로 이동
	else if (jd == 1) {
		for (int i = 0; i < n; i++) {
			temp.clear();
			for (int j = n - 1; j >= 0; j--) {
				if (board[i][j]) {
					if (!temp.empty() && temp.front() == board[i][j]) {
						int popped = temp.front();
						temp.pop_front();
						temp.push_front(popped * 2);
					}
					else {
						temp.push_front(board[i][j]);
					}
				}
			}
			while (temp.size() < n) {
				temp.push_front(0);
			}
			for (int j = n - 1; j >= 0; j--) {
				board[i][j] = temp[j];
			}
		}
	}

	//위로 이동
	else if (id == -1) {
		for (int j = 0; j < n; j++) {
			temp.clear();
			for (int i = 0; i < n; i++) {
				if (board[i][j]) {
					if (!temp.empty() && temp.back() == board[i][j]) {
						int popped = temp.back();
						temp.pop_back();
						temp.push_back(popped * 2);
					}
					else {
						temp.push_back(board[i][j]);
					}
				}
			}
			while (temp.size() < n) {
				temp.push_back(0);
			}
			for (int i = 0; i < n; i++) {
				board[i][j] = temp[i];
			}
		}
	}

	//아래로 이동
	else if (id == 1) {
		for (int j = 0; j < n; j++) {
			temp.clear();
			for (int i = n - 1; i >= 0; i--) {
				if (board[i][j]) {
					if (!temp.empty() && temp.front() == board[i][j]) {
						int popped = temp.front();
						temp.pop_front();
						temp.push_front(popped * 2);
					}
					else {
						temp.push_front(board[i][j]);
					}
				}
			}
			while (temp.size() < n) {
				temp.push_front(0);
			}
			for (int i = n - 1; i >= 0; i--) {
				board[i][j] = temp[i];
			}
		}
	}
}

void backtrack(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < n; i++) {
			ans = max(ans, *max_element(board[i], board[i] + n));
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		copy(&board[0][0], &board[0][0] + 400, &copied_board[cnt][0][0]);
		moving(di[i], dj[i]);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
			
		backtrack(cnt + 1);
		copy(&copied_board[cnt][0][0], &copied_board[cnt][0][0] + 400, &board[0][0]);
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

	cout << ans << endl;
	return 0;
}