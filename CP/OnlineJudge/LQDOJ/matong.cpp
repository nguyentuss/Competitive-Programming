#include <bits/stdc++.h>

using namespace std;

long long  n , x , a , b , modulo , ans = 0;

long long solve(long long x) {
    if (x == 1) return a%modulo;
    unsigned long long power = solve((x / 2)%modulo)%modulo;
    if (x % 2 != 0) return ((solve((x / 2 + 1)%modulo)%modulo)*power%modulo)%modulo;
    else return (power%modulo*power%modulo)%modulo;
}

long long power(long long x , long long y , long long p) {
	a = x; 
	modulo = p;
	return solve(y);
}

bool millerrabin(long long d , long long n){

	long long  a = 2;

	long long x = power(a , d , n);

	if (x == 1 && x == n - 1)
		return true;

	while (d != n - 1) {
		x = (x * x) % n;
		d *= 2;
		if (x == 1) return false;
		if (x == n - 1) return true;
	}
	return false;
}


bool isprime(long long  n) {
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;
	long long  d = n - 1;
	while (d % 2 == 0) d /= 2;

	for (long long  i = 0 ; i < 5 ; i++) 
		if (!millerrabin(d , n))
			return false;
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (long long  i = 0 ; i < n ; i++){
		cin >> x;
		//x = cbrt(x);
		if (isprime(x)) ans += x*2;
		else {
			long long  counting = 0;
			for (long long  j = 1 ; j * j * j <= x ; j++) {
				if (x % j == 0) {
					if (j == x / j) counting += 2;
					else counting += 3;
				} 
			}
			ans += counting*x;
		}
	}
	cout << ans;

	return 0;
}