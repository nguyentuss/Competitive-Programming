#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
#define int long long

int f[N][6];
int cnt1[N] , cnt2[N] , d[N];
int sum[N][5][2];
int mn[5];
int numch[5];
int d1[N] , d2[N];
int sta[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    mn[0] = 1; mn[1] = 10; mn[2] = 100; mn[3] = 1000; mn[4] = 10000;
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<int> v;
        v.push_back(0);
        for (char x : s) 
            v.push_back(x - 'A');
        int n = v.size() - 1;
        for (int i = 0 ; i <= n + 2 ; i++) {
            cnt1[i] = cnt2[i] = 0;
            sta[i] = d1[i] = d2[i] = 0; 
            for (int j = 0 ; j < 5 ; j++) {
                f[i][j] = sum[i][j][0] = sum[i][j][1] = 0;                 
            }
        }
        for (int i = n ; i >= 1 ; i --) {
            for (int j = 0 ; j < 5 ; j++) {
                if (j != v[i]) {
                    f[i][j] = f[i + 1][j];
                }
            }
            f[i][v[i]] = f[i + 1][v[i]] + 1;
        }
        int res = 0;
        for (int i = 1 ; i <= n ; i++) {
            int cnt = 0; 
            for (int j = v[i] + 1 ; j < 5 ; j++) {
                cnt += f[i + 1][j];
            }
            sta[i] = cnt;
            if (cnt) res -= mn[v[i]];
            else res += mn[v[i]]; 
        }
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 0 ; j < 5 ; j++) {
                if (j <= v[i]) cnt1[i] += f[i + 1][j];
                if (j > v[i]) cnt2[i] += f[i][j];
            }
            if (cnt1[i] == (n - i)) d1[i] = 1;
            if (cnt2[i] == 1) d2[i] = 1;
            for (int j = 0 ; j < 5 ; j++) {
                sum[i][j][1] = sum[i - 1][j][1] + (d2[i] && v[i] == j ? 1 : 0);
                sum[i][j][0] = sum[i - 1][j][0] + (d1[i] && v[i] == j ? 1 : 0);
            }
        }
        // for (int i = 0 ; i < 5 ; i++) {
        //     cerr << sum[1][i][0] << " ";
        // }
        int ans = res;
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 0 ; j < 5 ; j++) {
                int tt = (!sta[i]? -1 : 1);
                int cnt = 0;
                for (int k = j + 1 ; k < 5 ; k++) 
                    cnt += f[i + 1][k];
                int ttt = (!cnt ? 1 : -1);
                int tmp = res + tt*mn[v[i]] + ttt*mn[j];
                for (int k = j ; k < v[i] ; k++) {
                    tmp = tmp + 2*sum[i - 1][k][1]*mn[k];
                }
                for (int k = v[i] ; k < j ; k++) {
                    tmp = tmp - 2*sum[i - 1][k][0]*mn[k];
                }   
                ans = max(ans , tmp);
            }
        }   
        cout << ans << '\n';
    }

    return 0;
}