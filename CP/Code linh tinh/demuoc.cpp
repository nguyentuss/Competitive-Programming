#include <iostream>
#include <algorithm>

using namespace std;

int kq(int x , int n){
	int dau = x;
	int cuoi = (n/dau)*dau;
	return (cuoi - dau)/dau + 1;

}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("demuoc.inp","r",stdin);
	freopen("demuoc.out","w",stdout);
	int n , p , q , r ; 
	while (scanf("%d%d%d%d",&n,&p,&q,&r) == 4){
		int a = (p*q)/__gcd(p,q) , b = (q*r)/__gcd(q,r) , c = (p*r)/__gcd(p,r) , d = (a*r)/__gcd(a,r);
		cout << kq(a,n) + kq(b,n) + kq(c,n) - 3*kq(d,n) << endl;
	}
	return 0;
}