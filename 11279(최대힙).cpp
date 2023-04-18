#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int N, temp;
priority_queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp) {
			q.push(temp);
		}
		else {
			if (q.empty()) {
				cout << 0 << '\n';
			}
			else {
				int out = q.top();
				q.pop();
				cout << out << '\n';
			}
		}
	}

	return 0;
}