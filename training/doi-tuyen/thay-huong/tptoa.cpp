#include <iostream>
using namespace std;
#define long long long

void resursion(long n , long a){
	if (n == 0) return;
	char c = n % a;
	if (c <= 9) c+=48;
	else c += 55;
	resursion(n/a,a);
	cout << c;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("tptoa.inp","r",stdin);
	//freopen("tptoa.out","w",stdout);

	int t; cin >> t;
	while (t --) {
		long n; cin >> n;
		resursion(n , 16);
		cout << endl;
	}

	return 0;
}