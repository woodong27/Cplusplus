#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
int result = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		result *= i;
	}

	string result_str = to_string(result);

	int cnt = 0;
	for (int i = result_str.size() - 1; i >= 0; i--) {
		if (result_str[i] != '0') {
			break;
		}
		else {
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}