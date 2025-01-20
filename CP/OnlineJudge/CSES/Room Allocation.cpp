#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ii pair<int , int>

const int inf = 1e9 + 7;

struct times {
    int l , r , id;
};

bool cmp(times &a , times &b) {
    return a.r < b.r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<times> a;
    for (int i = 1 ; i <= n ; i++) {
        int l , r; cin >> l >> r; 
        a.push_back({l , r , i}); 
    }
    sort(a.begin() , a.end() , cmp);
    multiset<ii , greater<ii>> s;
    int ans = 0;
    vector<int> res(n + 1); 
    for (auto x : a) {
        int l = x.l , r = x.r , id = x.id;
        auto it = s.upper_bound(ii(l , 0));
        ii tm = *it;
        //cerr << tm.first << " " << tm.second << '\n';
        int room = 0;
        if (it == s.end()) {
            ans++;
            s.insert(ii(r , ans));
            room = ans;
        }
        else {
            int tmp = tm.second;
            s.erase(it);
            s.insert(ii(r , tmp));
            room = tmp;
        }
        res[id] = room;
    }
    cout << ans << '\n';
    for (int i = 1 ; i <= n ; i++) {
        cout << res[i] << " ";
    }
    return 0;
}