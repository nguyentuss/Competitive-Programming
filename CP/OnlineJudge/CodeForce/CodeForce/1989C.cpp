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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n); 
    for (int &u : a) cin >> u;
    for (int &u : b) cin >> u; 
    int A = 0 , B = 0;
    int C = 0 , D = 0;
    for (int i = 0 ; i < n ; i++) {
        if (a[i] > b[i]) A += a[i]; 
        else if (a[i] < b[i]) B += b[i];
        else if (a[i] == 1) C += 1;
        else if (a[i] == -1) D -= 1; 
    }
    //cerr << A << " " << B << '\n';
    while (C){
        if (A > B) B++;
        else A++;
        C--;
    }
    while (D){
        if (A < B) B--;
        else A--;
        D++;
    }
    cout << min(A , B) << '\n'; 
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