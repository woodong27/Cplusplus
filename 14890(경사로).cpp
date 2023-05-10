#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

//지도 nxn, 경사로의 높이=1, 길이=l
int n, l;
int map[100][100];
int ans = 0;

int check_row(int si, int sj) {
	deque<int> road;
	for (int i = 0; i < n; i++) {
		road.push_back(map[i][sj]);
	}
	
	deque<int> temp(road);
	int cnt = 0;
	int current = temp.front();
	temp.pop_front();
	int i = 1;
	while (!temp.empty()) {
		if (!cnt) {
			if (current == temp.front()) {
				i++;
				temp.pop_front();
			}
			else if (current - temp.front() == 1) {
				current = temp.front();
				temp.pop_front();
				i++;
				cnt++;
			}
			else if (current - temp.front() == -1) {
				if ()
			}
		}
	}
	

	cout << "row 성공" << endl;

	return 1;
}

int check_col(int si, int sj) {
	deque<int> road;
	for (int j = 0; j < n; j++) {
		road.push_back(map[si][j]);
	}
	
	int cnt = 0;
	for (int i = 0; i < n-1; i++) {
		if (road[i] - road[i + 1] == 1) {
			cnt++;
		}

	}

	cout << "col 성공" << endl;

	return 1;
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
			if (j == 0) {
				cout << i << ',' << j << endl;
				ans += check_col(i,j);
			}
			if (i == 0) {
				cout << i << ',' << j << endl;
				ans += check_row(i,j);
			}
		}
	}

	cout << ans << endl;

	return 0;
}