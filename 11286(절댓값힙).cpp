#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, temp;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp) {
			q.push({ abs(temp),temp });
		}
		else {
			if (q.empty()) {
				cout << 0 << '\n';
			}
			else {
				int out = q.top().second;
				q.pop();
				cout << out << '\n';
			}
		}
	}
	return 0;
}