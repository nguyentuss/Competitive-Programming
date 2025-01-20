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
const int N = 1e5 + 7;

int a[N];

void calc(int l , int r , int mid) {
    // 6 , 13 , 9
    int idx = l;
    vector<int> b; 
    vector<int> c;
    int cnt = mid - l;
    int right = r - 1;
    while (cnt > 0) {
        b.push_back(a[right]);
        right--;
        cnt--;
    }
    reverse(b.begin() , b.end()); 
    for (int i = l ; i <= right ; i++) c.push_back(a[i]);
    for (int x : b) {
        a[idx++] = x;
    }
    for (int x : c) {
        a[idx++] = x;
    }   
    
    // for (int i = 0 ; i < 5 ; i++) {
    //     cerr << a[i] << " ";
    // }
    // cerr << '\n';
}

int dac(int l , int r , int k , int cnt = 1) {
    //cerr << l << " " << r << " " << cnt << '\n';
    if (l + 1 == r || cnt == k) { 
        return cnt;
    }
    if (cnt + 2 <= k) {
        int mid = (l + r)/2; 
        //cerr << l << " " << r << " " << mid << " " << cnt + 2 << '\n';
        calc(l , r , mid);
        int dem = dac(l , mid , k , cnt + 2); 
        return dac(mid , r , k , dem);
    }
}
void solve() {
    int n , k; cin >> n >> k;
    for (int i = 0 ; i < n ; i++) a[i] = i + 1;
    if (dac(0 , n , k) != k) {
        cout << -1; 
        return;
    }
    //cerr << "DEBUG";
    for (int i = 0 ; i < n ; i++) {
        cout << a[i] << " ";
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }

}