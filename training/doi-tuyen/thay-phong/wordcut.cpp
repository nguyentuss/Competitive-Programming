#include <bits/stdc++.h>

using namespace std;

#define mod (ll) (1e9 + 7)
#define MAX_N (ll) (1e5 + 7)
#define ll long long

string a , b;
ll POW[MAX_N];
ll n , k , similar = 0;

void solvePOW() {
	POW[0] = 1;
	for (ll i = 1 ; i <= k ; i++) {
		POW[i] = (POW[i - 1]*n%mod)%mod; 
	}
	return;
}

void calc(bool status) {
	ll ans = 0 , prev = (status == 1 ? 1 : 0) , now = (status == 1 ? 1 : 0);
	for (ll i = 0 ; i < k ; i++) {
		now = ((POW[i]*similar)%mod - prev + mod)%mod;
		prev = now;
	}
	cout << now%mod;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("wordcut.inp","r",stdin);
	freopen("wordcut.out","w",stdout);
	cin >> a >> b;
	cin >> k;
	n = a.size() - 1;
	solvePOW();
	if (a == b) similar++;
	for (ll i = 1 ; i <= n ; i++) {
		string prefix = a.substr(0 , i);
		string suffix = a.substr(i, a.size() - i);
		if ((suffix + prefix) == b) similar++;
	}
	//cout << similar << '\n';
	if (a == b) calc(1);
	else calc(0);
	return 0;
}