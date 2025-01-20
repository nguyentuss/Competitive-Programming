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

string smallest(int n , int a , int b , int c) {
    a = a + n - (b + c + a); 
    string s = "";
    for (int i = 1 ; i <= a ; i++) s = s + (i & 1 ? '0' : '1');
    for (int i = 1 ; i <= b ; i++) s = s + (i & 1 ? 'A' : 'B');
    for (int i = 1 ; i <= c ; i++) s = s + (i & 1 ? 'a' : 'b');
    return s;
}
string largest(int n , int a , int b , int c) {
    c = c + n - (a + b + c); 
    string s = "";
    for (int i = 1 ; i <= c ; i++) s = s + (i & 1 ? 'z' : 'y');
    for (int i = 1 ; i <= b ; i++) s = s + (i & 1 ? 'Z' : 'Y');
    for (int i = 1 ; i <= a ; i++) s = s + (i & 1 ? '9' : '8');
    return s;
}

void solve() {
    int n, a , b , c; cin >> n >> b >> c >> a;    
    cout << smallest(n , a , b , c) << '\n';
    cout << largest(n , a , b , c) << '\n';
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