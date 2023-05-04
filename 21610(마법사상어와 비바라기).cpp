#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n, m;
int board[50][50];
int di[] = { 0,-1,-1,-1,0,1,1,1 };
int dj[] = { -1,-1,0,1,1,1,0,-1 };
deque<pair<int, int>> info;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int temp1 = 0; 
	int temp2 = 0;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		info.push_back({ temp1 - 1,temp2 });
	}


	return 0;
}