#include <bits/stdc++.h>

using namespace std;

#define mod (int) (1e9 + 7) 
#define max_n (int) (1e7 + 7)
vector <bool> eratosthenes(max_n , false);
int n;

long long power(long long x , long long y) {
	if (y == 0) return 1;
	long long child = power(x , y / 2)%mod;
	long long ans = (child*child)%mod;
	if (y % 2 == 0) return ans%mod;
	else return (ans*x)%mod;
}

long long cntn(int n , int i) {
	long long res = 0 , tmp = i;
	while (tmp <= n) {
		res += n/tmp;
		tmp*=i;
	}
	return res;
}

void sieve() {
	for (int i = 2 ; i * i <= n ; i++) {
		if (!eratosthenes[i]) {
			for (int j = i * i ; j <= n ; j += i) 
				eratosthenes[j] = true;
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	sieve();
	long long ans = 1;
	for (int i = 2 ; i*2 <= n ;i ++) {
		if (!eratosthenes[i]) {
			int cnt = cntn(n , i);
			//cout << cnt;
			if (cnt % 2 == 1) cnt--;
			ans = ans*power(i , cnt)%mod;
		}
	}
	cout << ans;

	return 0;
}