//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    pair<int, int> ab;
    ab.first = b.first - a.first;
    ab.second = b.second - a.second;
    pair<int, int> bc;
    bc.first = c.first - b.first;
    bc.second = c.second - b.second;
    int ret = ab.first*bc.second - ab.second*bc.first;
    if (ret > 0) return 1;
    else if (ret == 0) return 0;
    else return -1;
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    map<pair<int, int>, int> id;

    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        id[p[i]] = i;
    }

    vector<pair<int, int>> convexhull;
    for (int i = 0; i < n; i++) {
        // build upper hull first
        while (convexhull.size() >= 2 && ccw(convexhull[convexhull.size() - 1], convexhull[convexhull.size() - 2], p[i]) == 1) {
            convexhull.pop_back();
        }

        convexhull.push_back(p[i]);
    }

    vector<int> inHull(n);
    cout << n << '\n';
    for (auto u: convexhull) {
        cout << u.first << ' ' << u.second << '\n';
        inHull[id[u]] = 1;
    }

    for (int i = n-1; i >= 0; i--) {
        if (!inHull[i]) {
            cout << p[i].first << ' ' << p[i].second << '\n';
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    cout.tie(NULL);
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}

