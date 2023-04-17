#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int factories[100000] = { 0 };

int buying() {
	int result = 0;
	
	for (int i = 0; i < N; i++) {
		if (factories[i + 1] > factories[i + 2]) {
			int minv1 = min(factories[i], factories[i + 1] - factories[i + 2]);
			result += 5 * minv1;
			factories[i] -= minv1;
			factories[i + 1] -= minv1;

			int minv2 = min(factories[i], min(factories[i + 1], factories[i + 2]));
			result += 7 * minv2;
			factories[i] -= minv2;
			factories[i + 1] -= minv2;
			factories[i + 2] -= minv2;
		}
		else {
			int minv1 = min(factories[i], min(factories[i + 1], factories[i + 2]));
			result += 7 * minv1;
			factories[i] -= minv1;
			factories[i + 1] -= minv1;
			factories[i + 2] -= minv1;

			int minv2 = min(factories[i], factories[i + 1]);
			result += 5 * minv2;
			factories[i] -= minv2;
			factories[i + 1] -= minv2;
		}
		result += 3 * factories[i];
	}
	return result;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> factories[i];
	}

	int ans = buying();

	cout << ans << endl;

	return 0;
}