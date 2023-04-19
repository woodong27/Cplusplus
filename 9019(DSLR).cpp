#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int t, a, b;

 string dslr() {
	 int visited[10001] = { 0 };
	 string temp;
	 deque<pair<int, string>> q;
	 q.push_back({a,temp});
	 visited[a] = 1;
	 while (!q.empty()) {
		 int current = q.front().first;
		 string result = q.front().second;
		 if (current == b) {
			 return result;
		 }
		 q.pop_front();
		 int d1 = current / 1000;
		 int d2 = (current % 1000) / 100;
		 int d3 = ((current % 1000) % 100) / 10;
		 int d4 = (((current % 1000) % 100) % 10) % 10;
		 for (int i = 1; i <= 4; i++) {
			 int next;
			 if (i == 1) {
				 next = current * 2;
				 if (next > 9999) {
					 next %= 10000;
				 }
				 if (!visited[next]) {
					 q.push_back({ next, result+'D'});
					 visited[next] = 1;
				 }
			 }
			 else if (i == 2) {
				 next = current - 1;
				 if (next < 0) {
					 next = 9999;
				 }
				 if (!visited[next]) {
					 q.push_back({ next, result + 'S' });
					 visited[next] = 1;
				 }
			 }
			 else if (i == 3) {
				 next = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
				 if (!visited[next]) {
					 q.push_back({ next, result + 'L' });
					 visited[next] = 1;
				 }
			 }
			 else {
				 next = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
				 if (!visited[next]) {
					 q.push_back({ next, result + 'R' });
					 visited[next] = 1;
				 }
			 }	 
		 }
	 }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		cin >> a >> b;

		string ans = dslr();

		cout << ans << '\n';
	}
	return 0;
}