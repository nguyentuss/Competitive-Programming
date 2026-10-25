#include <bits/stdc++.h>
using namespace std;

#define MAX_N (int) (6e4 + 7)
#define inf (int) (MAX_N*3e4 + 7)
int n , t[MAX_N],r[MAX_N],f[MAX_N][2];

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("nktick.inp","r",stdin);
    freopen("nktick.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> t[i];
    for (int i = 1 ; i < n ; i++) cin >> r[i];
    f[1][0] = inf , f[1][1] = t[1], f[2][0]=r[1] ,f[2][1] = t[1]+t[2];
    for (int i=3;i<=n;i++) 
    {
        f[i][0] = f[i-1][1] - t[i-1] + r[i-1];
        f[i][1] = min(f[i-1][0],f[i-1][1])+t[i];
    }
    cout << min(f[n][0],f[n][1]);
    return 0;
}