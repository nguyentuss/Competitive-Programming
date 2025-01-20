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

int n;
char a[N];
int X[N];
int res = inf;

void write() {
    bool found = true;
//    for (int i = 1 ; i <= n + 1 ; i++) {
//        cout << X[i] << " ";
//    }
//    cout << '\n';
    for (int i = 1 ; i <= n ; i++) {
        if (a[i] == '<' && X[i] >= X[i + 1]) {
            found = false;
        }
        else if (a[i] == '>' && X[i] <= X[i + 1]) {
            found = false;
        }
    }
    if (found) {
        int ans = 0;
        for (int i = 1 ; i <= n + 1 ; i++) {
            //cout << X[i] << " ";
            ans += X[i];
        }
        //cout << '\n';
        res = min(res , ans);
    }
}

void backtr(int i) {
    for (int j = 0 ; j < 9 ; j++) {
        X[i] = j;
        if (i == (n + 1)) {
            write();
        }
        else backtr(i + 1);
    }

}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
//    freopen("test.inp","r",stdin);
//    freopen("test.out","w",stdout);
    freopen("input.inp","r",stdin);
    freopen("B.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    backtr(1);
    cout << res;
    return 0;
}
