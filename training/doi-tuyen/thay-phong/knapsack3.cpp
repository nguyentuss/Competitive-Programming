#include <bits/stdc++.h>
using namespace std;

const int lm=10001;
int n,w;
int a[lm],c[lm],f[lm][lm];

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> w;
    for (int i = 1; i <= n;i++)  cin >> a[i] >> c[i];
    /*for (int v=1;v<=w;v++) 
    {
        if (v>=a[1]) f[1][v]=c[1];
        else f[1][v]=0;
    }*/
    for (int i=1;i<=n;i++) 
        for (int v=0;v<=w;v++) 
            if (a[i]<=v) f[i][v] = max(f[i-1][v], f[i][v-a[i]]+c[i]);
            else f[i][v]=f[i-1][v];
    cout << f[n][w];
    return 0;
}