#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

#define ii pair<int , int>
#define iii pair<ii , int>
#define fi first 
#define se second
int mark[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m , q; cin >> n >> m >> q;
    string st; cin >> st;
    vector<ii> range;
    for (int i = 0 ; i <= n ; i++) {
        mark[i] = -1;
    }
    for (int i = 1 ; i <= m ; i++) {
        int l , r; cin >> l >> r;
        l-- , r--;
        range.push_back(ii(l , r));
    }
    set<int> s;
    vector<int> v;
    for (int i = 0 ; i < n ; i++) s.insert(i);
    for (int i = 0 ; i < m ; i++) {
        auto it = s.lower_bound(range[i].fi);
        vector<int> pos;
        while (it != s.end() && (*it) <= range[i].se) {
            pos.push_back(*it);
            v.push_back(pos.back());
            mark[pos.back()] = v.size() - 1;
            it++;
        }
        while (pos.size()) {
            s.erase(pos.back());
            pos.pop_back();
        }
    }
    int cnt = 0 , ans = 0;
    for (auto x : st) {
        if (x == '1') cnt++;
    }
    for (int i = 0 ; i < n ; i++) {
        cerr << mark[i] << " ";
    }
    for (int i = 0 ; i < min(cnt ,(int )v.size()) ; i++) {
        if (st[v[i]] == '0') ans++;
    }
    while (q--) {
        int ask; cin >> ask;
        ask--;
        if (mark[ask] != -1 && mark[ask] < cnt) {
            if (st[ask] == '0') ans--;
            else ans++;
        }
        if (st[ask] == '0') {
            st[ask] = '1';
            if (cnt < v.size() && st[v[cnt]] == '0') ans++;
            cnt++;
        }
        else {
            st[ask] = '0';
            if (cnt > 0 && cnt <= v.size() && st[v[cnt - 1]] == '0') ans--;     
            cnt--;   
        }
        cout << ans << '\n';
    }
    return 0;
}