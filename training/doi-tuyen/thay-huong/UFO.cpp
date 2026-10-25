#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX_N (int) (1e4 + 7)
ll n , m , k , v[MAX_N][MAX_N] , x , y , r , ans = 0;
int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cout.tie(NULL);
	//freopen("UFO.inp","r",stdin);
	//freopen("UFO.out","w",stdout);
    cin >> n >> m >> k;
    for (int day = 1 ; day <= k ; day++)
    {
        for (int i = 1 ; i <= n ; i++)
            for (int j = 1 ; j <= m ; j++) v[i][j]++ , ans++;
        cin >> x >> y >> r;
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= m ; j++)
            {
                if ( (x - i) * (x - i) + (y - j) * (y - j) <= r * r){
                    ans -= v[i][j] ;
                    v[i][j] = 0;
                }
            }
        }
    }
    cout << ans;
}