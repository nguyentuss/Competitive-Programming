//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repn(i ,a, b) for(int i = a; i <= (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define vi vector<int>
#define fi first
#define se second
#define int long long
#define sz(a) (int) a.size()
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

int n , m; 

bool checkInside(int x , int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

void solve() {
    cin >> n >> m;
    string s; cin >> s;
    int x = 1 , y = 1; 
    int opx = 0 , opy = 0;
    int mxx = 0 , mxy = 0;
    int mnx = inf , mny = inf;
    for (char c : s) {
        if (c == 'L') opy --;
        if (c == 'R') opy ++;
        if (c == 'U') opx --;
        if (c == 'D') opx ++;
        mxx = max(mxx , opx); mnx = min(mnx , opx);
        mxy = max(mxy , opy); mny = min(mny , opy);
        int cnt = 0;
        if (!checkInside(x + opx , y + opy)) {
            if (c == 'L' && checkInside(x , y + 1) && checkInside(x + mxx , y + 1 + mxy) && checkInside(x + mnx , y + 1 + mny)) y++ , cnt++;
            if (c == 'U' && checkInside(x + 1 , y) && checkInside(x + 1 + mxx , y + mxy) && checkInside(x + 1 + mnx , y + mny)) x++ , cnt++;
            if (c == 'R' && checkInside(x , y - 1) && checkInside(x + mxx , y - 1 + mxy) && checkInside(x + mnx , y - 1 + mny)) y-- , cnt++;
            if (c == 'D' && checkInside(x - 1 , y) && checkInside(x - 1 + mxx , y + mxy) && checkInside(x - 1 + mnx , y + mny)) x-- , cnt++;
            if (!cnt) break;
        }
        //cerr << c << " " << x << " " << y << " " << mxx << " " << mxy << " " << mnx << " " << mny << '\n';
    }
    cout << x << " " << y << '\n';
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}