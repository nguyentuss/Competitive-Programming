#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

vector<int> pos[MAX_N];
int f[MAX_N][2];
int a[MAX_N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    freopen("test.inp","r",stdin);
    int t; cin >> t;
    while (t--) {
        int n , k; cin >> n >> k;
        for (int i = 1 ; i <= k ; i++) pos[i].clear();
        for (int i = 1 ; i <= n ;i++) {
            cin >> a[i];
            f[i][0] = f[i][1] = 0;
            pos[a[i]].push_back(i);
        }
        for (int i = 1 ; i <= k ; i++) {
            sort(pos[i].begin() , pos[i].end());
        }

        bool found = true;
        for (int i = 2 ; i <= k ; i++) {
            if (!pos[i].size() || !pos[i - 1].size()) {
                cout << 0 << '\n';
                found = false;
                break;
            }
            else {
                int len = pos[i].size();
                int len1 = pos[i - 1].size();
                f[i][1] = max(f[i - 1][0] + abs(pos[i][len - 1] - pos[i - 1][0]) 
                    , f[i - 1][1] + abs(pos[i][len - 1] - pos[i - 1][len1 - 1]));
                f[i][0] = max(f[i - 1][0] + abs(pos[i][0] - pos[i - 1][0]) 
                    , f[i - 1][1] + abs(pos[i][0] - pos[i - 1][len1 - 1]));
            }
        }
        //cout << f[2][0] << " " << f[2][1];
        if (found)
            cout << max(f[k][0] , f[k][1]) << '\n';
    }
    return 0;
}