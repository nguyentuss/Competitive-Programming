#include <bits/stdc++.h>
using namespace std;

#define N 207
#define inf (1e9)
double C[N][N];
int n , m;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("csmarket.inp","r",stdin);
    freopen("csmarket.out","w",stdout);

    cin >> n >> m;
    for (int i = 1 ; i <= 200 ; i++) {
        for (int j = 1 ; j <= 200 ; j++) {
            C[i][j] = inf;
        }
    }
    for (int i = 1 ; i <= n ; i++) C[i][i] = 0.0;


    for (int i = 1 ; i <= m ; i++) {
        int u, v;
        double w;
        cin >> u >> v >> w;
        C[u][v] = C[v][u] = w;
    }

    for (int k = 1 ; k <= n; k++) {
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                if (C[i][j] > C[i][k] + C[k][j]) 
                    C[i][j] = C[i][k] + C[k][j];
            }
        }
    }
    int maxi = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n; j++) {
            cout << fixed << setprecision(2) << C[i][j] << " ";
        }
        cout << '\n';
    }
    /*double temp = maxi;
    cout << fixed << setprecision(2) << temp;*/

    return 0;
}