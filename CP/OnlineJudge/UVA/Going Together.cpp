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
typedef vector<pii> vii;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int inf = 1e15;
#define x first
#define y second
#define vl(p) [p[0].x][p[0].y][p[1].x][p[1].y][p[2].x][p[2].y]
#define vc(p) [p.x][p.y]

int dx[] = {0 , 0 , -1 , 1}; 
int dy[] = {1 , -1 , 0 , 0};

int vis[10][10][10][10][10][10];
int d[10][10][10][10][10][10];
int n;
char a[10][10];
vii trap;

bool inside(pii p) {
    return (p.x >= 0 && p.y >= 0 && p.x < n && p.y < n);
}

void init() {
    trap.clear();
    for (int xa = 0 ; xa <= n ; xa++) {
        for (int ya = 0 ; ya <= n ; ya++) {
            for (int xb = 0 ; xb <= n ; xb++) {
                for (int yb = 0 ; yb <= n ; yb++) {
                    for (int xc = 0 ; xc <= n ; xc++) {
                        for (int yc = 0 ; yc <= n ; yc++) {
                            vis[xa][ya][xb][yb][xc][yc] = 0;
                            d[xa][ya][xb][yb][xc][yc] = inf;
                        }
                    }
                }
            }
        }
    }
}


int bfs(vii p) {
    queue<vii> q; 
    q.push(p);
    vis vl(p) = 1;
    d vl(p) = 0;
    sort(trap.begin() , trap.end());
    while (!q.empty()) {
        vii u = q.front();
        q.pop();
        int mn = d vl(u);
        if ((a vc(u[0])) == 'X' && (a vc(u[1])) == 'X' && (a vc(u[2])) == 'X') {
            return mn;
        }
        for (int i = 0; i < 4 ; i++) {
            vii v = u;
            for (int j = 0 ; j < 3 ; j++) {
                v[j].x += dx[i]; 
                v[j].y += dy[i];
                bool colide = 0; 
                if (!inside(v[j]) || (inside(v[j]) && (a vc(v[j]) == '#'))) {
                    v[j] = u[j];
                }
            }   
            for (int l = 0 ; l < 3 ; l++) {
                for (int j = 0 ; j < 3 ; j++) {
                    for (int k = 0 ; k < 3 ; k++) {
                        if (j != k) {
                            if (v[j] == v[k]) {
                                v[j] = u[j];
                            }
                        }
                    }
                }
            }
            assert(v[0] != v[1] && v[0] != v[2] && v[1] != v[2]);
            if (!(vis vl(v))) {
                d vl(v) = min(d vl(v) , mn + 1);
                vis vl(v) = 1; 
                q.push(v);
            }
        }
    }
    return inf;
}

int cnt_test = 0;
int ok;

void solve() {
    cin >> n;
    init();
    vii v;
    cnt_test++;
    for (int i = 0 ; i < n ;i ++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> a[i][j];
            if (a[i][j] >= 'A' && a[i][j] <= 'C') {
                v.emplace_back(i , j);
            }
            if (a[i][j] == 'X') {
                trap.emplace_back(i , j);
            }
        }
    }
    int F = bfs(v);
    cout << "Case " << cnt_test << ": ";
    if (F == inf) cout << "trapped\n";
    else cout << F << '\n';
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