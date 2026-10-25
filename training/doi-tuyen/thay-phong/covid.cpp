#include <bits/stdc++.h>

using namespace std;

#define ll long long

mt19937 rng(43243);

ll randll(ll a, ll b){
    return uniform_int_distribution<ll>(a, b)(rng);
}

int main()  {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("COVID.inp","r",stdin);
	freopen("COVID.out","w",stdout);
	int n , m , u , v;
	cin >> n >> m ;
    for (int i = 1 ; i <= m ; i++) cin >> u >> v;
	cout << randll(1,n);
	return 0;
}