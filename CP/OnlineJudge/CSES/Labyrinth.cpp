#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

char a[N][N];
int n , m;  
int dx[] = {1 , -1 , 0 , 0}; 
int dy[] = {0 , 0 , 1 , -1};
char dd[] = {'D' , 'U' , 'R' , 'L'};
int dx1[] = {-1 , 1 , 0 , 0}; 
int dy1[] = {0 , 0 , -1 , 1};
int f[N][N];
int trace[N][N];

bool check(ii A) {
    return (1 <= A.fi && A.fi <= n && 1 <= A.se && A.se <= m);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    ii s , t;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j <= m ; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') s = ii(i , j);
            if (a[i][j] == 'B') t = ii(i , j);
        }
    }
    queue<ii> q; q.push(s); 
    while (!q.empty()) {
        ii pos = q.front(); 
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            ii A = ii(pos.fi + dx[i] , pos.se + dy[i]);
            if (check(A) && !f[A.fi][A.se] && a[A.fi][A.se] != '#') {
                f[A.fi][A.se] = f[pos.fi][pos.se] + 1;
                q.push(A);
                trace[A.fi][A.se] = i;
            }   
        }
    }
    if (f[t.fi][t.se]) {
        cout << "YES" << '\n';
        cout << f[t.fi][t.se] << '\n';
        int tm = f[t.fi][t.se];
        int pos_x = t.fi , pos_y = t.se;
        vector<char> tr;
        while (tm) {
            tm--; 
            int tmp = trace[pos_x][pos_y];
            pos_x += dx1[tmp];
            pos_y += dy1[tmp];
            tr.push_back(dd[tmp]);
        }
        reverse(tr.begin() , tr.end()); 
        for (auto x : tr) {
            cout << x;
        }
    }
    else {
        cout << "NO";
    }
    return 0;
}