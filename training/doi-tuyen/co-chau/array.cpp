#include <bits/stdc++.h>

using namespace std;

#define M (long long) (1e9 + 7)

long long n , k , a;
vector <long long> fact(10000000);
vector <long long> invfact(10000000);

long long C(long long n , long long k) {
	return ((fact[n] * invfact[k])%M*invfact[n - k])%M;
}

long long solve(long long x) {
    if (x == 1) return a%M;
    long long power = solve((x / 2))%M;
    if (x % 2 != 0) return ((solve((x / 2 + 1)))%M*power%M)%M;
    else return (power*power)%M;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("array.inp","r",stdin);
	freopen("array.out","w",stdout);
	cin >> n;
	k = n;
	n = 2*n - 1;
	fact[0] = 1;
	for (int i = 1 ; i <= n ; i++) fact[i] = (i * fact[i - 1])%M;
	a = fact[n];
	invfact[n] = (solve(M - 2))%M;
	a = fact[k];
	invfact[k] = (solve(M - 2))%M;
	a = fact[n - k];
	invfact[n - k] = (solve(M - 2))%M;
	cout << (2*C(n , k)%M - k + M)%M;
	return 0;
}