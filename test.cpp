#include <iostream>
#include <deque>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> temp;
	temp.push_back(10);
	temp.push_back(30);
	temp.push_back(5);

	int minv = *min_element(temp.begin(), temp.end());

	cout << minv;
}