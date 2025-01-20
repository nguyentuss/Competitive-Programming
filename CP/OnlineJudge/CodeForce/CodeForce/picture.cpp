#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll mod = 1e9 + 7;

int main(){
	ll n; cin >> n;
	ll f1 = 1, f2 = 1 , fi;
	for (int i = 3 ; i <= n + 2 ; i++) 
		{
			fi = (f1 + f2) % mod;
			f1 = f2 ;
			f2 = fi;
		}
	cout << fi;
	return 0;
}