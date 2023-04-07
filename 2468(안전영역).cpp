#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int N;
int map[101][101];
int visited[101][101];
int rain = 0;

void bfs() {

}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}



	return 0;
} 