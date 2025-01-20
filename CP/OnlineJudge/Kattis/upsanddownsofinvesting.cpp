//source:: https://open.kattis.com/problems/upsanddownsofinvesting?tab=metadata
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
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        int s , n , m; cin >> s >> n >> m;
        vector<int> a(s + 1);
        for (int i = 1 ; i <= s ; i++) 
            cin >> a[i];
        int peak , valley;
        peak = valley = 0;
        int cnt = 0;
        bool status = 0;
        vector<int> up_1(s + 1 , 1);
        vector<int> down_1(s + 1 , 1);
        vector<int> down_2(s + 1 , 1);
        vector<int> up_2(s + 1 , 1);
        for (int i = 2 ; i <= s ; i++) {
            if (a[i] > a[i - 1]) {
                up_1[i] = up_1[i - 1] + 1;
            }
            if (a[i] < a[i - 1]) {
                down_1[i] = down_1[i - 1] + 1;
            }
        }
        for (int i = s - 1; i >= 1 ; i--) {
            if (a[i] < a[i + 1]) {eqwe
                up_2[i] = up_2[i + 1] + 1; 
            }
            if (a[i] > a[i + 1]) {
                down_2[i] = down_2[i + 1] + 1;
            }
        }
        for (int i = 1 ; i <= s ; i++) {
            if (up_1[i] >= n && down_2[i] >= n) {
                peak++;
            }
            if (down_1[i] >= m && up_2[i] >= m) {
                valley++;
            }
        }
        cout << peak << " " << valley; 
    }
    return 0;
}