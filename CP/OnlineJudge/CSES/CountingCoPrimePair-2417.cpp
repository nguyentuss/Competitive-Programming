#include <bits/stdc++.h>

using namespace std;

#define MAX_VAL (int) (1e6  + 7)
#define ll long long
#define MAX_N (int) (1e5 + 7)

vector <int> divisorOF[MAX_VAL];
vector <int> valdivisor(MAX_VAL);
vector <int> v(MAX_N);
ll ans = 0;
int n;

void sieve() {	
	for (int i = 2 ; i < MAX_VAL ; i++) {
		if (divisorOF[i].size() == 0) {
			divisorOF[i].push_back(i);
			for (int j = 2 * i ; j < MAX_VAL ; j+=i) {
				divisorOF[j].push_back(i);
			}
		}
	}
}

void calc() { 
	for (int i = 0 ; i < n ; i++) {
		int x = v[i];
		for (int mask = 0 ; mask < (1<<divisorOF[x].size()) ; mask++) {
			int combination = 1 ;
			int primeDivisor = 0;
			for (int pos = 0 ; pos < divisorOF[x].size() ; pos++) {
				if ((1<<pos)&mask) {
					combination *= divisorOF[x][pos];
					primeDivisor++;
				}
			}
			if (primeDivisor & 1) ans -= valdivisor[combination];
			else ans += valdivisor[combination];
			valdivisor[combination] ++;	
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	/*cin >> n;
	for (int i = 0 ; i < n ; i++) {
		cin >> v[i];
	}*/
	calc();
	cout << ans << '\n';

	return 0;
}