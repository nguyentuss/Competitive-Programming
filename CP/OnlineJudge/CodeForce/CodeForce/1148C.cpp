//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define le(x) (x << 1ll)
#define ri(x) ((x << 1ll) + 1)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n) , pos(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i] , a[i] --;
        pos[a[i]] = i;
    } 
    vector<pii> ans;
    for (int i = 0 ; i < n ; i++) {
        if (pos[i] == i) continue;
        if (abs(pos[i] - i) >= n/2) {
            ans.push_back(pii(pos[i] , i)); 
        }
        else {
            if (pos[i] < n/2 && i < n/2) {
                ans.push_back(pii(pos[i]  , n-1));
                ans.push_back(pii(n-1 , i));
                ans.push_back(pii(n-1 , pos[i]));
            }
            else if (pos[i] >= n/2 && i >= n/2) {
                ans.push_back(pii(pos[i] , 0));
                ans.push_back(pii(0 , i));
                ans.push_back(pii(0 , pos[i]));
            }
            else {
                int p1 = pos[i]; 
                int p2 = i; 
                if (p1 > p2) swap(p1 , p2);
                ans.push_back(pii(p1 , n - 1));
                ans.push_back(pii(p2 , 0));
                ans.push_back(pii(0 , n - 1)); 
                ans.push_back(pii(0 , p2));
                ans.push_back(pii(n-1,p1));
                
            }
            
            // int tmp = pos[i];
            // pos[i] = i;
            // pos[a[tmp]] = tmp;
        }
        int tmp = pos[i];
        swap(pos[i],pos[a[i]]);
        swap(a[tmp] , a[i]);
        // for (int j = 0 ; j < n ; j++) cout << pos[j] << " ";
        // cout << '\n'; 
    }
    
    cout << sz(ans) << '\n';
    for (auto [i , j] : ans) {
        cout << i+1 << " " << j+1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test; 
    test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
 
}
