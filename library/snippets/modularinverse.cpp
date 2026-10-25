#include <bits/stdc++.h>

using namespace std;

int n , m , a , b;

int extended_euclidean(int a , int b , int *x , int *y) {
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	int x1 , y1;
	int gcd = extended_euclidean(b , a%b , &x1 , &y1);
	*x = y1;
	*y = x1 - (a / b)*y1;
	return gcd;
}

int moduloinverse(int n , int m) {
	int x , y;
	int gcd = extended_euclidean(n , m , &x , &y);
	if (gcd != 1) return -1;
	cout << x << " " << y << '\n';
	return (x%m + m)%m;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> n >> m;
	cout << moduloinverse(n ,m);

	return 0;
}