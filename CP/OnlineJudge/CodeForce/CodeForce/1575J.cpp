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
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

int a[N][N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        int n , m , k; cin >> n >> m >> k;
        auto inside = [&](int x, int y) -> bool {
            return (1 <= x && 1 <= y && y <= m);
        };
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1 ; i <= k ; i++) {
            int y; cin >> y;
            int x = 1; 
            while (x <= n) {
                //cerr << x << " " << 
                if (a[x][y] == 1 && inside(x , y + 1)) {
                    a[x][y] = 2;
                    y++;
                } 
                else if (a[x][y] == 2 && inside(x + 1 , y)) {
                    x++;
                }
                else if (a[x][y] == 3 && inside(x , y - 1)) {
                    a[x][y] = 2;
                    y--;
                }
            }
            cout << y << " ";
        }
    }
    return 0;
}