#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve(int n, int px, int py, int qx, int qy, const vector<int>& a) {
    int dx = abs(qx - px);
    int dy = abs(qy - py);

    int dist = dx + dy;

    int total_len = 0;
    for (int i = 0; i < n; i++) {
        total_len += a[i];
    }

    if (total_len < dist) {
        cout << "No\n";
        return;
    }

    if ((total_len - dist) % 2 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        solve(n, px, py, qx, qy, a);
    }

    return 0;
}
