#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
 
#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<ii , int>
#define fi first
#define se second
const int inf = 1e9 + 7;
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

int l[MAX_N] , r[MAX_N]; 
int cnt[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int k , n; cin >> k >> n; 
    vector<iii> a;
    map<int , int> m;
    for (int i = 1 ; i <= n ; i++) {
         cin >> l[i] >> r[i];
         a.push_back(iii(ii(l[i] , r[i]) , i));
         m[r[i]] = l[i];
    }   
    sort(a.begin() , a.end()); 
    set<ii , greater<ii>> s1;
    set<int , greater<int>> s2;
    set<int> ss;
    s1.insert(ii(k , -1));
    vector<ii> ans;
    map<int , int> cn;
    map<int , int> cc;
    for (int i = 0 ; i < a.size() ; i++) {
        auto it = s2.lower_bound(a[i].fi.fi);
        while (it != s2.end()) {
            int x = *it; 
            int mid = cn[m[x]];
            auto it1 = ss.upper_bound(mid);
            int mr = *it1;
            it1--;
            int ml = *it1;
            s1.insert(ii(cc[ml] + 1 + cc[mr] , -ml));
            s1.erase(ii(cc[ml] , -ml));
            s1.erase(ii(cc[mr] , -mr));
            cc[ml] = cc[ml] + 1 + cc[mr];
            cc[mr] = 0;
            ss.erase(mr);
            s2.erase(it);
            it = s2.lower_bound(a[i].fi.fi);
        }
        auto ee = *s1.begin();
        int top = ee.fi;
        int left = ee.se;
        left = -left;
        if (top % 2 == 0) {
            s1.insert(ii(top/2 - 1 , -left));
            s1.insert(ii(top/2 , -(left + top/2)));
            ss.insert(left); 
            ss.insert(left + top/2);
            ans.push_back(ii(a[i].se , left + top/2 - 1));
            cn[a[i].fi.fi] = left + top/2 - 1;
            cc[left] = top/2 - 1;
            cc[left + top/2] = top/2;
        }
        else {
            s1.insert(ii(top/2 , -left));
            s1.insert(ii(top/2 , -(left + top/2 + 1)));
            ss.insert(left);
            ss.insert(left + top/2 + 1);
            ans.push_back(ii(a[i].se , left + top/2));
            cn[a[i].fi.fi] = left + top/2;
            cc[left] = top/2;
            cc[left + top/2 + 1] = top/2;
        }
        s2.insert(a[i].fi.se);
        s1.erase(s1.begin());
    }
    sort(ans.begin() , ans.end());
    for (auto x : ans) cout << x.se << " ";
    return 0;
}



// 6 7 3 8 2 9 3 5 2 31
// 6 6 3 3 2 2 2 2 2 2 