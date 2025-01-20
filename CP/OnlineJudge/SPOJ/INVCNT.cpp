//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int n; cin >> n;
    vector<pii> a(n); 
    int res = 0;
    for (int i = 0 ; i < n ; i++) cin >> a[i].first , a[i].second = i;
    sort(a.begin() , a.end() , greater<pii>());
    vector<int> b(n);
    for (int i = 0 ; i < n ; i++) {
        b[i] = a[i].second;
        //cerr << b[i] << " ";
    }
    auto merge = [&](vector<int> &l , vector<int> &r) -> vector<int> {
        int i = 0 , j = 0; 
        vector<int> ans;
        while (i < sz(l) && j < sz(r)){
            if (l[i] < r[j]) {
                res = res + sz(r) - j;
                ans.push_back(l[i++]); 
            }
            else ans.push_back(r[j++]);
        } 
        while (i < sz(l)) ans.push_back(l[i++]); 
        while (j < sz(r)) ans.push_back(r[j++]);
        return ans;
    };
    auto merge_sort = [&](int l , int r , auto &&merge_sort) -> vector<int>{
        if (l == r) return {b[l]};
        int mid = (l + r) >> 1;
        vector<int> left = merge_sort(l , mid , merge_sort);
        vector<int> right = merge_sort(mid + 1 , r , merge_sort);
        return merge(left , right);
    };
    vi p = merge_sort(0 , n - 1 , merge_sort);
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    cin >> test;
    while (test--) {
        solve();
    }

}