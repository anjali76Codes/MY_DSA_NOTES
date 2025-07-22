/*
 * Author: yashchavan
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e18;
const ld EPS = 1e-9;
const int N = 2e5 + 5;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef LOCAL
    #define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
    #define debug(x)
#endif

template<typename T> void _print(T x) {cerr << x;}
template<typename T, typename V> void _print(pair<T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template<typename T> void _print(vector<T> v) {cerr << "["; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template<typename T> void _print(set<T> s) {cerr << "["; for (auto i : s) {_print(i); cerr << " ";} cerr << "]";}
template<typename T> void _print(multiset<T> s) {cerr << "["; for (auto i : s) {_print(i); cerr << " ";} cerr << "]";}
template<typename T, typename V> void _print(map<T, V> m) {cerr << "["; for (auto i : m) {_print(i); cerr << " ";} cerr << "]";}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int power(int a, int b, int m = MOD) {
    int res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int mod_inv(int a, int m = MOD) {
    return power(a, m - 2, m);
}

bool solve(vector<int>& h , int n , int k) {
     k--; // Convert to 0-based index
    
    // Find the maximum height and its index
    int max_height = *max_element(h.begin(), h.end());
    int max_index = -1;
    for (int i = 0; i < n; i++) {
        if (h[i] == max_height) {
            max_index = i;
            break;
        }
    }

    // Calculate the time to reach the tower with the max height
    int time_to_reach_max = abs(k - max_index);
    int water_time_limit = h[k];

    // If the time to reach the max height tower is less than the water level limit, return YES
    return time_to_reach_max < water_time_limit;
}
signed main() {
    fastio
    int t = 1;
    cin >> t;
   while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> h(n);
        
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        if (solve(h , n , k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}