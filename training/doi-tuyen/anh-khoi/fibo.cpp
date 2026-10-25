#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

unsigned long long n;

long long F[100000];

unsigned long long fibo(int n){
	if (F[n] != -1) return F[n];
	if (n == 0) {
		F[n] = 0;
		return 0;
	}
	if (n == 1) {
		F[n] = 1;
		return 1;
	}
	F[n] = fibo(n - 1) + fibo(n - 2);
	return F[n];

}

int main(){
	boost;
	F[0] = F[1] = 1;
	cin >> n;
	cout << fibo(n);
	return 0;
}