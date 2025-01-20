#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int k , l , m , n , S; 

int single(int x) {
	return S / x;
}
int dou(int a , int b ) {
	return ((a * b)/__gcd(a,b));
}
int trip(int a , int b , int c) {
	int temp = dou(b , c);
	return dou(a , temp);
}

int quad(int a , int b , int c , int d) {
	int temp = trip(b , c , d);
	return dou(a , temp);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> k >> l >> m >> n >> S;

	int A = single(k) , B = single(l) , C = single(m) , D = single(n);
	int AB = S/dou(k , l) , AC = S/dou(k , m) , AD = S/dou(k , n) , BC = S/dou(l , m) , BD = S/dou(l , n) , CD = S/dou(m , n);
	int ABC = S/trip(k , l , m) , ABD = S/trip(k , l , n) , ACD = S/trip(k , m , n)  , BCD = S/trip(l , m , n);
	int ABCD = S/quad(k , l , m , n);	

	cout << A + B + C + D - AB - AC - AD - BC - BD - CD + ABC + ABD + ACD + BCD - ABCD;

	return 0;
}