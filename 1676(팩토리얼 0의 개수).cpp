#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int mul5 = N / 5;
	int mul25 = N / 25;
	int mul125 = N / 125;

	int ans = mul5 + mul25 + mul125;

	cout << ans << '\n';

	return 0;
}