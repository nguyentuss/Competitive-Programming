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
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 37;
const int MOD = 1e9 + 7;

int C[N][N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        int n; cin >> n;
        for (int i = 0 ; i <= n ; i++) {
            C[i][0] = C[i][i] = 1;
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= i ; j++) {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1]; 
            }
        }
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j <= i ; j++) {
                cout << C[i][j] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}