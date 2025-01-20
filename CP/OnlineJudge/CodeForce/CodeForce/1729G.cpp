#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 5e2 + 7;
const int MOD = 1e9 + 7;

// la so cach toi thieu de xoa het tat ca t thang khi xet den i thang
// + if [i - m + 1 , i] == t 
// option 1 : chọn đoạn đó g[i] = g[i - m] + 1; 
// option 2 : bỏ đoạn đó đi chọn những đoạn từ [j - m + 1 , j] với j thuộc [i , i - m + 1]
//         => g[i] = g[j - m] + 1
// Lấy min lại
// + 

int f[N];
int cnt[N];
bool isfound[N][N];

void init(int n) {
    for (int i = 1 ; i <= n ;i ++) {
        f[i] = inf;
        cnt[i] = 0;
        for (int j = 1 ; j <= n ;j ++) {
            isfound[i][j] = 0;
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; cin >> test;
    while (test--) {
        string s , t; cin >> s >> t;
        int n = s.size() , m = t.size();
        init(n);
        s = ' ' + s;
        for (int i = 1 ; i <= n ;i ++) {
            string tm = "";
            for (int j = i ; j <= i + m - 1 ; j ++) {
                tm += s[j]; 
            }
            //cerr << i << " " << i + m - 1 << " " << tm << '\n';
            if (tm == t) isfound[i][i + m - 1] = true;
        }   
        for (int i = 1 ; i <= n ; i ++) {
            int l = i - m + 1;
            if (l >= 1 && isfound[l][i]) {
                f[i] = f[i - m] + 1;
                for (int j = l ; j <= i ; j++) {
                    int li = j - m + 1;
                    if (li >= 1 && isfound[li][j]) {
                        f[i] = min(f[i] , f[li - 1] + 1);
                    }
                }
            }
            else {
                f[i] = f[i - 1];
            }
        } 
        cnt[0] = 1;
        for (int i = 1 ; i <= n ;i ++) {
            int l = i - m + 1;
            if (l >= 1 && isfound[l][i]) {
                if ((f[i - m] + 1) == f[i]) {
                    if (f[i] == 1) {
                        cnt[i] = (cnt[i] + 1)%MOD;
                    }
                    else {
                        cnt[i] = (cnt[i] + cnt[i - m])%MOD;
                    }
                }
                for (int j = l ; j < i ; j++) {
                    int li = j - m + 1;
                    if (li >= 1 && isfound[li][j]) {
                        if ((f[li - 1] + 1) == f[i]) {
                            if (f[i] == 1) {
                                cnt[i] = (cnt[i] + 1)%MOD;
                            }
                            else {
                                cnt[i] = (cnt[i] + cnt[li - 1])%MOD;
                            }
                        }
                    }
                }
            }
            else {
                cnt[i] = cnt[i - 1];
            }
        }
        cout << f[n] << " " << cnt[n] << '\n';
    }
    return 0;
}