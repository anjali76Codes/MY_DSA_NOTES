#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int a, b;
        long long x, y;
        cin >> a >> b >> x >> y;

        // If a == b, cost is zero
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }

        // If a > b, we cannot decrease a (operations only increase or toggle LSB)
        if (a > b) {
            cout << -1 << "\n";
            continue;
        }

        // We want to transform a into b using only +1 or XOR 1 operations

        // BFS or DP approach:
        // Since a,b <= 100, small state space, we can do BFS over states

        const int MAXN = 201;
        vector<long long> dist(MAXN, LLONG_MAX);
        dist[a] = 0;

        deque<int> dq;
        dq.push_back(a);

        while (!dq.empty()) {
            int cur = dq.front();
            dq.pop_front();

            // Operation 1: a = a + 1 (cost x)
            if (cur + 1 <= 200 && dist[cur] + x < dist[cur + 1]) {
                dist[cur + 1] = dist[cur] + x;
                dq.push_back(cur + 1);
            }

            // Operation 2: a = a XOR 1 (cost y)
            int nxt = cur ^ 1;
            if (nxt <= 200 && dist[cur] + y < dist[nxt]) {
                dist[nxt] = dist[cur] + y;
                dq.push_back(nxt);
            }
        }

        if (dist[b] == LLONG_MAX)
            cout << -1 << "\n";
        else
            cout << dist[b] << "\n";
    }

    return 0;
}
