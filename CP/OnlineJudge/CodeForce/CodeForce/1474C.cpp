#include <bits/stdc++.h>

#pragma GCC targer("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 2e3 + 7;
const int MOD = 1e9 + 7;

vector<int> a(MAX_N);
int n;
vector<ii> v;

bool check(int x) {
    multiset<int> s;
    v.clear();
    for (int i = 1 ; i <= 2*n ;i++) s.insert(a[i]);
    int tmp = x;
    while (!s.empty()) {
        int max_ele = *s.rbegin();
        s.erase(s.find(max_ele));
        auto it = s.find(x - max_ele);
        //cerr << x << " " << max_ele << " " << *it << '\n';
        if (it == s.end()) 
            return false;
        v.push_back(ii(max_ele, *it));
        x = max(*it , max_ele);
        s.erase(it);
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> n; a.assign(2*n + 1 , 0);
        for (int i = 1 ; i <= 2*n ;i ++) 
            cin >> a[i];
        sort(a.begin() + 1 , a.begin() + 1 + 2*n);
        
        bool found = false;
        for (int i = 1 ; i < 2*n ; i++) {
            int x = a[i] + a[2*n];
            if (check(x)) {
                cout << "YES" << '\n';
                cout << x << '\n';
                for (auto e : v) {
                    cout << e.first << " " << e.second << '\n';
                }
                found = true;
                break;
                //cout << x << " ";
            }
        }
        if (!found) cout << "NO" << '\n';
    }
    return 0;
}