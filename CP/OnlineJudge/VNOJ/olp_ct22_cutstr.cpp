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
const int base = 3e11 + 3;
const int N = 1e4 + 7;

void solve() {
    string s; cin >> s; 
    int n = sz(s); 
    s = " " + s; 
    /* HASHING*/
    vector<int> hash(n + 7) , pw(n + 7) , revpw(n + 7), revhash(n + 7);
    pw[0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        pw[i] = pw[i - 1] * base;
        hash[i] = hash[i - 1]*base + (s[i] - 'a' + 1); 
    } 
    revpw[n + 1] = 1;
    for (int i = n ; i >= 1 ; i--) {
        revpw[i] = revpw[i + 1] * base; 
        revhash[i] = revhash[i + 1] * base + (s[i] - 'a' + 1);
    }

    function<int(int , int)> getHash = [&](int l , int r) {
        return (hash[r] - hash[l - 1]*pw[r - l + 1]);
    };

    function<int(int , int)> getrevHash = [&](int l , int r) {
        return (revhash[l] - revhash[r + 1]*pw[r - l + 1]);
    };

    function<bool(int , int)> checkPalindrome = [&](int l , int r) {
        int hash = getHash(l , r); 
        int rHash = getrevHash(l , r);
        return (hash == rHash);
    };

    /*HASHING*/
    
    int q; cin >> q;
    vector<vector<int>> queries(q);
    set<int> listLength;
    for (int i = 0 ; i < q ; i++) {
        int c; cin >> c;
        for (int j = 0 ; j < c ; j++) {
            int x; cin >> x;
            queries[i].push_back(x);
            listLength.insert(x);
        }
    }
    vector<vector<int>> listPanli_Length(N);
    for (auto length : listLength) {
        for (int i = 1 ; i <= n ; i++) {
            if (checkPalindrome(i , i + length - 1)) {
                listPanli_Length[length].push_back(i);
            }
        }
    }
    for (auto listEle_queries : queries) {
        int num_Ele = sz(listEle_queries);
        // for (int x : listEle_queries) {
        //     cout << x << " ";
        // }
        // cout << '\n';
        vector<int> f(1 << num_Ele , inf);
        f[0] = 0;
        for (int mask = 0 ; mask < (1 << num_Ele) ; mask++) {
            for (int i = 0 ; i < num_Ele ; i++)  {
                if (!(mask & (1 << i))) {
                    int len = listEle_queries[i]; 
                    int l = 0 , r = sz(listPanli_Length[len]) - 1; 
                    int pos = -1;
                    while (l <= r){
                        int mid = (l + r) >> 1; 
                        if (listPanli_Length[len][mid] > f[mask]) {
                            pos = listPanli_Length[len][mid];
                            r = mid - 1;
                        }
                        else l = mid + 1;
                    }
                    if (pos != -1) {
                        f[mask | (1 << i)] = min(f[mask | (1 << i)] , pos + len - 1);
                    }
                }
            }
        }
        if (f[(1 << num_Ele) - 1] <= n) {
            cout << "YES\n";
        }
        else cout << "NO\n";
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