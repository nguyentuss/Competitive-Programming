#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

unsigned long long  n , x , m , ans;

unsigned long long power(unsigned long long  x , unsigned long long  n) {
	if (n == 0) return 1%m;
	unsigned long long  child = power(x , n / 2)%m;
	unsigned long long  ans = (child%m*child%m)%m;
	if (n % 2 == 1) ans = (ans%m * x%m)%m;

	return ans%m;
}

unsigned long long  sum(unsigned long long  x , unsigned long long  n) {
	if (n == 0) return 1%m;
	ans = sum(x , (n - 1) / 2)%m;
	if (n % 2 != 0) ans = (ans*(1 + power(x , n / 2 + 1)%m)%m)%m;
	else {
		ans = (ans%m*(1 + power(x , n / 2)%m)%m)%m;
		ans = (ans%m + power(x , n)%m)%m;
	}
	return ans%m;
}

int main(){
	boost;
	int test;
	cin >> test;
	for (int i = 1 ; i <= test ; i++) {
		cin >> x >> n >> m;
		cout << sum(x , n) << endl;
	}

	return 0;
}