#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<char , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 507 ;
const int MOD = 1e9 + 7;

char a[MAX_N][MAX_N];
int vis[MAX_N][MAX_N];
int n, m; 
int dx[] = {0 , 0 , 1 , -1 };
int dy[] = {1 , -1 , 0 , 0 };
//         phai trai xuong len
int c[4][8];

bool check(int x , int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

struct seg {
    int x , y , oper;
};

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // freopen("planet1.inp","r",stdin);
    // freopen("planet1.out","w",stdout);
    cin >> n >> m;
    c[0][0] = 2;
    c[0][1] = 3;
    c[0][2] = 0;
    c[0][3] = 1;
    c[1][0] = 3;
    c[1][3] = 0;
    c[1][1] = 2;
    c[1][2] = 1;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> a[i][j];
        }
    }
    string inf1 = "\\/\\/";
    string inf2 = "/\\/\\";
    queue<seg> q; 
    int A , B; cin >> A >> B;
    int ans = 0;
    bool found = false;
    for (int i = 0 ; i < 4 ; i++) {
        int dist = 0;
        if (a[A][B] == '/') {
            dist = 1;
            if (!check(nx , ny) || (check(nx , ny) && a[nx][ny] == 'C')) {
                dist++;
                break;
            }
            q.push({A + dx[c[1][i]] , B + dy[c[1][i]] , c[1][i]});
        }
        else if (a[A][B] == '\\') {
            dist = 1;
            q.push({A + dx[c[0][i]] , B + dy[c[0][i]] , c[0][i]});
        }
        else if (a[A][B] == 'C') {
            continue;
        }
        else q.push({A , B , i});
        //cout << A << " " << B << " " << i << '\n
        vector<pair<char , ii>> vv;
        while (!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            //cerr << x << " " << y << '\n';
            int oper = q.front().oper;
            q.pop();
            int nx = x + dx[oper];
            int ny = y + dy[oper];
            if (!check(nx , ny) || (check(nx , ny) && a[nx][ny] == 'C')) {
                dist++;
                break;
            }
            if (a[nx][ny] == '\\') {
                dist++;
                q.push({nx , ny , c[0][oper]});
                vv.push_back(iii(a[nx][ny] , ii(nx , ny)));
            }
            if (a[nx][ny] == '/') {
                dist++;
                q.push({nx , ny , c[1][oper]});
                vv.push_back(iii(a[nx][ny] , ii(nx , ny)));
            }
            if (a[nx][ny] == '.') {
                dist++;
                q.push({nx , ny , oper});
            }
            if (vv.size() >= 4) {
                string tmp = "";
                vector<ii> coor; 
                for (int j = vv.size() - 4 ; j < vv.size() ; j++) {
                    tmp += vv[j].fi;
                    coor.push_back(vv[j].se);
                }
                sort(coor.begin() , coor.end());
                ii n1 = ii(coor[0].fi , coor[3].se);
                ii n2 = ii(coor[3].fi , coor[0].se);
                if ((n1 == coor[1] && n2 == coor[2]) && (tmp == inf1 || tmp == inf2)) {
                    found = true;
                    break;
                }
            }
        }
        if (found) break;
        ans = max(ans , dist);
    }
    if (found) cout << "Voyager";
    else cout << ans;

    return 0;
}