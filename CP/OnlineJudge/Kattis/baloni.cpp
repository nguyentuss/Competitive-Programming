//source:: https://open.kattis.com/problems/baloni
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 1e6 + 7 ;
const int MOD = 1e9 + 7;

int a[N]; 
int H[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    //cin >> test;
    while (test--) {
        int n; cin >> n;
        for (int i = 0 ; i < n ; i++) cin >> a[i];
        int ans = 0;
        for (int i = 0 ; i < n ; i++) {
            H[a[i]] ++;
            if (H[a[i] + 1] == 0) {
                ans++;
            }
            else {
                H[a[i] + 1] --;
            }
        }
        cout << ans;
    }
    return 0;
}