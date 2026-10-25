#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int , int>
#define sz(x) (int)x.size()

const int N = 1e3 + 7;
const int inf = 1e9 + 7;

int f[N][N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string a; cin >> a;
    string b; cin >> b;
    int n = a.size();
    int m = b.size();
    b = " " + b;
    a = " " + a;
    for (int i = 0 ; i <= n ;i ++) {
        for (int j = 0 ; j <= m ; j++) {
            f[i][j] = inf;
        }
    }
    f[0][0] = 0;
    for (int i = 1 ; i <= n ;i ++) {
        for (int j = 1 ; j <= m ; j++) {
            if (a[i] == b[j]) {
                if (a[i] == '*') f[i][j] = min({f[i][j - 1] , f[i - 1][j] , f[i - 1][j - 1]});
                else f[i][j] = f[i - 1][j - 1] + 1;
                continue;
            }
            if (a[i] == '?' || b[j] == '?') f[i][j] = f[i - 1][j - 1] + 1;
            if (a[i] == '*') f[i][j] = min({f[i - 1][j - 1] + 1 , f[i - 1][j], f[i][j - 1] + 1});
            if (b[j] == '*') f[i][j] = min({f[i - 1][j - 1] + 1 , f[i][j - 1], f[i - 1][j] + 1});
        }
    }
    // for (int i = 1 ; i <= n ; i++) {
    //     for (int j = 1 ; j <= m ; j++) {
    //         cerr << f[i][j] << " ";
    //     }
    //     cerr << '\n';
    // }
    if (f[n][m] > 1e8) {
        cout << "No solution!";
        return 0;
    }
    int i = n, j = m;
    vector<char> res;
    //cout << a[6] << " " << b[6];
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            if (a[i] != '*') {
                if (a[i] == '?') res.push_back('A'); 
                else res.push_back(a[i]);
                i--;
                j--;
            }
            else {
                if (f[i][j] == f[i - 1][j]) {
                    i--;
                }
                else if (f[i][j] == f[i][j - 1]) {
                    j--;
                }
                else if (f[i][j] == f[i - 1][j - 1]) {
                    i--;
                    j--;
                }
                //cerr << i << " " << j << " " << b[j] << '\n';
            }
        }
        else {
            // if (a[i] == '?' && b[j] == '*' && f[i][j] > f[i - 1][j]) {
            //     res.push_back('A');
            //     i--;
            // } 
            // else if (a[i] == '*' && b[j] == '?' && f[i][j] > f[i][j - 1]) {
            //     res.push_back('A');
            //     j--;
            // }
            if (('A' <= a[i] && a[i] <= 'Z' && b[j] == '?')) {
                res.push_back(a[i]);
                i--;
                j--;
            }
            else if (('A' <= b[j] && b[j] <= 'Z' && a[i] == '?')) {
                res.push_back(b[j]);
                i--;
                j--;
            }
            else if (('A' <= a[i] && a[i] <= 'Z') || a[i] == '?' && b[j] == '*') {
                //cerr << "YES" << i << " " << j << '\n';
                if (a[i] == '?') a[i] = 'A';
                if (f[i][j] == (f[i - 1][j - 1] + 1)) {
                    res.push_back(a[i]);
                    i --;
                    j--;
                }
                else if (f[i][j] == f[i][j - 1]) {
                    j--;
                }
                else if (f[i][j] == (f[i - 1][j] + 1)) {
                    res.push_back(a[i]);
                    i--;
                }
            }
            else if (('A' <= b[j] && b[j] <= 'Z') || b[j] == '?' && a[i] == '*') {
                if (b[j] == '?') b[j] = 'A';
                if (f[i][j] == (f[i - 1][j - 1] + 1)) {
                    res.push_back(b[j]);
                    i --;
                    j--;
                }
                else if (f[i][j] == f[i - 1][j]) {
                    i--;
                }
                else if (f[i][j] == (f[i][j - 1] + 1)) {
                    res.push_back(b[j]);
                    j--;
                }
            }
        }
        //cerr << i << " " << j << '\n';
    }
    reverse(res.begin() , res.end());
    for (auto x : res) cout << x;
    return 0;
}