#include <bits/stdc++.h>

using namespace std;

#define MAX_VAL (int) (1e6  + 7)
#define ll long long

vector <int> divisorOF[MAX_VAL];
vector <int> valdivisor(MAX_VAL);
ll ans = 0;

void sieve() {	
	for (int i = 2 ; i  < MAX_VAL ; i++) {
		if (divisorOF[i].size() == 0) {
			divisorOF[i].push_back(i);
			for (int j = 2 * i ; j < MAX_VAL ; j+=i) {
				divisorOF[j].push_back(i);
			}
		}
	}
}

void calc(int x , int ask) { 
	for (int mask = 0 ; mask < (1<<divisorOF[x].size()) ; mask++) {
		int combination = 1 ;
		int primeDivisor = 0;
		for (int pos = 0 ; pos < divisorOF[x].size() ; pos++) {
			if ((1<<pos)&mask) {
				combination *= divisorOF[x][pos];
				primeDivisor++;
			}
		}
		if (ask == 1) {
			if (primeDivisor & 1) ans -= valdivisor[combination];
			else ans += valdivisor[combination];
			valdivisor[combination] ++;	
		}
		else {
			valdivisor[combination]--;
			if (primeDivisor & 1) ans += valdivisor[combination];
			else ans -= valdivisor[combination];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	freopen("inp.inp","r",stdin);
	freopen("out.out","w",stdout);
	sieve();
	//for (auto e : divisorOF[5]) cout << e << " ";
	int askquery; cin >> askquery;
	while (askquery--) {
		int operation , num; cin >> operation >> num;
		calc(num , operation);
		cout << ans << '\n';
	}

	return 0;
}