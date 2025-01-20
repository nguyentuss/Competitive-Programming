#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int a[N];
int group[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        a[i] %= 3;  
    }
    int gr1 = 0 , gr2 = 0;
    // TH 1 : Z = 0
    for (int i = 1 ; i <= n ; i++) {
        if (a[i] == 0) {
            gr1++;
        }
    }
    if (gr1 <= n/2) {
        cout << 0 << '\n';
        bool status = false;
        for (int i = 1 ; i <= n ; i++) {
            if (!a[i]) {
                cout << 0;
            }
            else if (n/2 - gr1 > 0 && !status) {
                gr1++;
                cout << 0;
                if (!(n/2 - gr1)) status = true;
            }
            else cout << 1;
        }   
        return 0;
    }
    else if (gr1 > n/2) {
        cout << 2 << '\n';
        int cnt = 0;
        bool status = false;
        for (int i = 1 ; i <= n ; i++) {
            if (!a[i]) cnt++;
            if (status || a[i] > 0) cout << 1;
            else cout << 0;
            if (cnt == n/2) status = true;
        }
    }
    else if (gr1 == 0 || gr1 == n) {
        cout << 1 << '\n';
        for (int i = 1 ; i <= n ; i++) {
            if (i <= n/2) cout << 0;
            else cout << 1;
        }
    }
    else cout << -1;

    return 0;
}