#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    cout.tie(NULL);
    int n; cin >> n;
    map<int , int> cnt;
    int ans = 0;
    for (int i = 1 ; i <= n ;i ++) {
        int x; cin >> x;
        auto it = cnt.upper_bound(x);
        if (it == cnt.end()) {
            ans++;
        }
        else {
            cnt[it->first]--;
            if (!cnt[it->first]) cnt.erase(it);
        }
        cnt[x]++;
        cerr << ans << " ";
    }
    cout << ans << '\n';
    return 0;
}