#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int t, n;
string p, nums;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> p;
		cin >> n;
		cin >> nums;

		deque<int> numbers;
		string temp;
		
		for (int i = 0; i < nums.size(); i++) {
			if (isdigit(nums[i])) {
				temp += nums[i];
			}
			else {
				if (temp.size() >= 1) {
					numbers.push_back(stoi(temp));
					temp = "";
				}
			}
		}
		
		int flag = 0;
		int rev = 0;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				if (!rev) {
					rev = 1;
				}
				else {
					rev = 0;
				}
			}
			else {
				if (numbers.empty()) {
					flag = 1;
					break;
				}
				else if (rev == 0) {
					numbers.pop_front();
				}
				else if (rev == 1) {
					numbers.pop_back();
				}
			}
		}
		if (rev) {
			reverse(numbers.begin(), numbers.end());
		}

		string ans;
		if (flag) {
			ans = "error";
		}
		else {
			if (numbers.empty()) {
				ans = "[]";
			}
			else {
				ans += "[";
				for (int i = 0; i < numbers.size(); i++) {
					ans += to_string(numbers[i]);
					if (i == numbers.size() - 1) {
						ans += "]";
					}
					else {
						ans += ",";
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}