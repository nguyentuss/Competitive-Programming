#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 2e3 + 7;
const int MOD = 1e9 + 7;

int x[10];
int n = 15 , k = 5;

void write() {
    map<int , int> m;
    for (int a = 0 ; a <= 1 ; a++) {
        for (int b = 0; b <= 1 ; b++) {
            for (int c = 0 ; c <= 1 ; c++) {
                for (int d = 0 ; d <= 1 ; d++) {
                    for (int e = 0 ; e <= 1 ; e++) {
                        int sum = a + b + c + d + e ;
                        if (sum > 0) {
                            m[a*x[1] + b*x[2] + c*x[3] + d*x[4] + e*x[5]]++;
                        }
                    }
                }
            }
        }
    }
    bool found = true;
    for (auto x : m) {
        if (x.second > 1) {
            found = false;
            break;
        }
    }
    if (found)
        cout << "CO THOA: ";
    else cout << "KO THOA: ";
    for (int i = 1 ; i <= k ; i++) {
        cout << x[i] << " ";
    }
    cout << '\n';
}

void backtr(int i) {
    for (int j = x[i - 1] + 1 ; j <= n - k + i ; j ++) {
        x[i] = j;
        if (i == k) {
            write();
        }
        else backtr(i + 1);
    }
}

signed main() {
    //freopen("check.inp","r",stdin);
    //freopen("check.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    backtr(1);
    return 0;
}