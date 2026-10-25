#include <iostream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

int n;

int ans(int n , int a , int b , int c){
	if (n == 0) return 0;
	else {
		ans(n - 1,a , c , b);
		//cout << n << " " << a << " " << b << " " << c << endl;
		cout << a << " " << c << endl;
		ans(n - 1,b , a ,c);
	}
	return 0;
}

int main() {
	boost;
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("THAPHN.inp","r",stdin);
	freopen("THAPHN.out","w",stdout);
	cin >> n;
	ans(n,1,2,3);
	return 0;
}