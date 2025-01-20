//source:: 
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
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    cin >> test;
    while (test--) {
        int k; cin >> k;
        vector<int> a(27);
        for (int i = 1 ; i <= 20 ; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1 ; i <= 20 ;i ++) {
            int key = a[i];
            int j = i - 1; 
            if (key < a[j]) {
                while (j > 0 && key < a[j]) {
                    a[j + 1] = a[j]; 
                    j --;
                }
                a[j + 1] = key;
                ans += abs(i - j) - 1;
            }
            //cerr << i << " ";
        }
        cout << k << " " << ans << '\n';
    }
    return 0;
}