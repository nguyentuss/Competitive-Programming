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
const int N = 5e2 + 7;
const int MOD = 1e9 + 7;

// f[i][j][match] is minimum cost khi xet toi i cua xau a
// xet toi j cua xau b va match duoc 

int f[2][N][N];
int pi[N];
int aut[N][2];
int n , m;

void KMP(string &a) {
    for (int i = 1 ; i < m  ; i++) {
        int j = pi[i - 1];
        while (j > 0 && a[i] != a[j]) {
            j = pi[j - 1];
        }
        if (a[i] == a[j]) j++;
        pi[i] = j;
    }
    return;
}

void KMP_automaton(string &a) {
    for (int i = 0 ; i < m ; i++) {
        for (int c = 0 ; c < 2 ; c++) {
            if (a[i] - '0' == c) {
                aut[i][c] = i + 1;
            }
            else {
                if (i > 0) {
                    aut[i][c] = aut[pi[i - 1]][c];
                }
            }
        }
    }
    return;
}

void DP(string &a , string &b) {
    for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j < N ; j++) {
            for (int k = 0 ; k < N ; k++) {
                f[i][j][k] = inf;
            }
        }
    }
    f[0][0][0] = 0;
    for (int i = 0 ; i < n ; i ++) {
        int cur = i & 1;
        int nxt = cur ^ 1;
        for (int j = 0 ; j < m ; j++) {
            for (int k = 0 ; k <= (n - m + 1) ; k++) {
                if (f[cur][j][k] == inf) continue;
                for (int c = 0 ; c < 2 ; c++) {
                    int a_i = a[i] - '0';
                    int cost = (a_i == c ? 0 : 1);
                    int nj = aut[j][c];
                    int match = 0;
                    if (nj == m) {
                        match = 1;
                        nj = pi[m - 1];
                    }
                    f[nxt][nj][k + match] = min(f[nxt][nj][k + match] , f[cur][j][k] + cost);
                }
            }
        }
        cerr << cur << " " << nxt << '\n';
        for (int j = 0 ; j < m ; j++) {
            for (int k = 0 ; k <= (n - m + 1) ; k++) {
                f[cur][j][k] = inf;
            }
        }
    }
    //cerr << pi[m - 1];
    for (int k = 0 ; k <= (n - m + 1) ; k++) {
        int ans = inf;
        for (int j = 0 ; j < m ; j++) {
            //cerr << f[n][j][k] << " ";
            ans = min(ans , f[n & 1][j][k]);
        }
        //cerr << '\n';
        cout << (ans == inf ? -1 : ans) << " ";
    }
}

void solve() {
    cin >> n >> m;
    string a; cin >> a;
    string b; cin >> b;
    KMP(b);
    KMP_automaton(b); 
    DP(a , b);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}