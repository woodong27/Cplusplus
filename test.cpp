#include <iostream>
#include <deque>
#include <tuple>

using namespace std;

int main() {

	deque<pair<pair<int, int>, int>> temp;

	temp.push_back({ {1,1},1 });

	cout << temp.front().first.first << temp.front().first.second << temp.front().second << endl;
}