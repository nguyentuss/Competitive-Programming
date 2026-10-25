#include <bits/stdc++.h>

using namespace std;

int f[107][107 * 107];

int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1 ; i <= n ; i++) cin >> a[i] , sum += a[i];
    vector<vector<int>> P(n + 1 , vector<int>(sum + 1 , -1));
    f[0][0] = 1;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1; j <= sum ; j++) {
            f[i][j] = max(f[i][j] , f[i - 1][j]);
            if (j - a[i] >= 0 && f[i - 1][j - a[i]] == 1) {
                f[i][j] = 1;
                P[i][j] = i;
            }
        }
    } 
    if (sum % 2 == 0) {
        if (f[n][sum] && f[n][sum / 2]) {
            vector<int> trace;
            int x = n , y = sum/2;
            while (x > 0 && y > 0) {
                if (P[x][y] != -1) {
                    trace.push_back(P[x][y]); 
                    y = y - a[P[x][y]];
                    x --;
                }
                else {
                    x --;
                }
            }
            multiset<int> s;
            for (int i = 1 ; i <= n ; i++) s.insert(i);
            for (int x : trace) {
                cout << x << " ";
                s.erase(s.find(x));
            }
            cout << '\n';
            for (int x : s) cout << x << " ";
        }
        else cout << "NO";
    }
    else cout << "No solution";
    return 0;
}