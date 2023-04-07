#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int visited[100001];
    for (int i = 0; i < 100001; i++) {
        visited[i] = -1;
    }
    visited[N] = N;
    int ans = 0;

    deque<pair<int, int>> q;
    q.push_back(make_pair(N, 0));

    while (!q.empty()) {
        int current = q.front().first;
        int cnt = q.front().second;
        q.pop_front();

        if (current == K) {
            ans = cnt;
            break;
        }

        int next[3] = { current * 2, current + 1, current - 1 };
        for (int i = 0; i < 3; i++) {
            if (0 <= next[i] && next[i] <= 100000 && visited[next[i]] == -1) {
                visited[next[i]] = current;
                q.push_back(make_pair(next[i], cnt + 1));
            }
        }
    }

    cout << ans << endl;

    deque<int> path;
    int start = K;

    while (true) {
        path.push_front(start);
        start = visited[start];
        if (start == N) {
            break;
        }
    }

    if (path.front() != N) {
        path.push_front(N);
    }

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }

    return 0;
}
