#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)

int n;
vector<int> v;
int divisor[MAX_N];
int f[MAX_N];
int trace[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("coins.inp","r",stdin);
	freopen("coins.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i * i <= n ; i++) {
		if (!(n % i)) {
			if (i == n / i) 
				v.push_back(i);
			else {
				v.push_back(i);
				v.push_back(n / i);
			}
		}
	}
	sort(v.begin() , v.end());
	int len = v.size();
	for (int i = 0 ; i < v.size() ; i++) {
		divisor[i + 1] = v[i];
	//	cout << v[i] << " ";
	}
	f[1] = 1;
	for (int i = 2 ; i <= len ; i++) {
		for (int j = 1 ; j < i ; j++) {
			if (divisor[i] % divisor[j] == 0) {	
				if (f[i] < f[j] + 1) {
					f[i] = f[j] + 1;
					trace[i] = j;
				}
			}
		}
	}
	//cout << f[len] << '\n';
	while (len != 0) {
		cout << divisor[len] << " ";
		len = trace[len];
	}
	return 0;
}