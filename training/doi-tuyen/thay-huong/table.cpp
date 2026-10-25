#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846

int main(void)
{
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("table.inp","r",stdin);
	//freopen("table.out","w",stdout);
	long double n,R,r;
	cin >> n >> R >> r;
	if (r>R) {
		cout << "NO";
		return 0;
	}
	if (2*r>R)
    {
		if(n == 1) cout << "YES";
		else cout << "NO";
		return 0;	
	}
	if (n*asin(r*1.0/(R-r)) <= 1e-9 + PI) cout << "YES";
	else cout << "NO";
	return 0;
}