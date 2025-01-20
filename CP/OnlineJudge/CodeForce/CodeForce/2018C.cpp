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
    int n, k ;cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    int num_zero = 0;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] == 0) num_zero ++;
    }
    if (num_zero == n) {
        cout << min(k , num_zero) << '\n'; 
        return;
    }
    int cnttt = 0;
    
    sort(all(a) , greater<int>());
    for (int i = 0 ; i < n ; i++) {
        if (a[i] < a[0]) cnttt ++;
    }
    //cout << cnttt;
    if (sum % a[0] == 0) {
        int hehe = sum/a[0];
        cout << hehe + min(k/a[0] , n - hehe) << '\n';
    }
    else {
        if (k >= (a[0] - (sum % a[0]))) {
            cout << sum/a[0] + 1 + min((max(0ll , k-(a[0] - (sum % a[0]))))/a[0] , n - (sum/a[0] + 1)) << '\n';
        }
        else {
            int x = sum/a[0];
            //cerr << x;
            int remain = sum%a[0];
            int anss = 1;
            vector<int> ans;
            for (int i = 1 ; i * i <= x ; i++) {
                if (x % i == 0) {
                    if (x/i != i) {
                        ans.push_back(x/i);
                    }
                    ans.push_back(i);
                }   
            }
            
            for (int c : ans) {
                //cerr << c << " ";
                if (k >= (c - 1)*remain)
                    anss = max(anss , c);
            }
            cout << anss << '\n';
            //cout << 1 << '\n';
        }
    }
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