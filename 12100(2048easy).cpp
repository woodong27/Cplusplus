#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int n;
int board[20][20];
int copied_board[5][20][20];
int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };
int ans = 0;

// 똑같은 수가 세개 있으면 이동하려는 방향의 칸이 먼져 합쳐지게 됨
void moving(int id, int jd) {
	deque<pair<int, int>> temp;

	// 왼쪽으로 이동
	if (jd == -1) {
		for (int i = 0; i < n; i++) {
			temp.clear();
			for (int j = 0; j < n; j++) {
				if (board[i][j]) {
					if (temp.empty()) {
						temp.push_back({ board[i][j],0 });
					}
					else {
						if (temp.back().first == board[i][j] && !temp.back().second) {
							temp.back().second = board[i][j];
						}
						else {
							temp.push_back({ board[i][j],0 });
						}
					}
				}
			}
			while (temp.size() < n) {
				temp.push_back({0,0});
			}
			for (int j = 0; j < n; j++) {
				board[i][j] = temp[j].first+temp[j].second;
			}
		}
	}

	//오른쪽으로 이동
	else if (jd == 1) {
		for (int i = 0; i < n; i++) {
			temp.clear();
			for (int j = n - 1; j >= 0; j--) {
				if (board[i][j]) {
					if (temp.empty()) {
						temp.push_front({ board[i][j],0 });
					}
					else {
						if (temp.front().first == board[i][j] && !temp.front().second) {
							temp.front().second = board[i][j];
						}
						else {
							temp.push_front({ board[i][j],0 });
						}
					}
				}
			}
			while (temp.size() < n) {
				temp.push_front({ 0,0 });
			}
			for (int j = n - 1; j >= 0; j--) {
				board[i][j] = temp[j].first + temp[j].second;
			}
		}
	}

	//위로 이동
	else if (id == -1) {
		for (int j = 0; j < n; j++) {
			temp.clear();
			for (int i = 0; i < n; i++) {
				if (board[i][j]) {
					if (temp.empty()) {
						temp.push_back({ board[i][j],0 });
					}
					else {
						if (temp.back().first == board[i][j] && !temp.back().second) {
							temp.back().second = board[i][j];
						}
						else {
							temp.push_back({ board[i][j],0 });
						}
					}
				}
			}
			while (temp.size() < n) {
				temp.push_back({ 0,0 });
			}
			for (int i = 0; i < n; i++) {
				board[i][j] = temp[i].first+temp[i].second;
			}
		}
	}

	//아래로 이동
	else if (id == 1) {
		for (int j = 0; j < n; j++) {
			temp.clear();
			for (int i = n - 1; i >= 0; i--) {
				if (board[i][j]) {
					if (temp.empty()) {
						temp.push_front({ board[i][j],0 });
					}
					else {
						if (temp.front().first == board[i][j] && !temp.front().second) {
							temp.front().second = board[i][j];
						}
						else {
							temp.push_front({ board[i][j],0 });
						}
					}
				}
			}
			while (temp.size() < n) {
				temp.push_front({ 0,0 });
			}
			for (int i = n - 1; i >= 0; i--) {
				board[i][j] = temp[i].first + temp[i].second;
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