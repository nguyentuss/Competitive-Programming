#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
const int inf = 1e9 + 7;

int a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    vector<int> v;
    set<int> s;
    for (int i = 0 ; i < n ; i++) {
        s.insert(a[i]);
        if (a[i] != a[i + 1]) {
            v.push_back(a[i]);
        }
    }
    int ans = inf;
    for (auto c : s) {
        int tmp = 1;
        for (auto x : v) {
            if (x != c) tmp++;
        }
        ans = min(ans , tmp);
    }
    cout << ans;

    return 0;
}