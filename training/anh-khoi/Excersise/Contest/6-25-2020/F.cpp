#include <bits/stdc++.h>

using namespace std;

string l , r;
int lena , lenb;

long long solve(string x , int pos) {
	long long ans =0 ;
	for (int i = 0 ; i <= pos ; i++) 
		ans = ans*10 + (x[i] - '0');
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		cin >> l >> r;
		lena = l.size() , lenb = r.size();
		while (lena != lenb) {
			l = '0' + l;
			lena ++;
		}
		long long ans = 0 , a , b;
		for (int i = lena - 1 ; i >= 0 ; i --) {
			a = solve(l , i);
			b = solve(r , i);
			ans += (b - a);
		}
		cout << ans << '\n';
	}
	return 0;
}