#include <bits/stdc++.h>
using namespace std;
long long d=0, i, r, n, odd;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("number1.inp", "r", stdin);
	freopen("number1.out", "w", stdout);
	cin >> r;
	for (i=1; i<=r; i++){
		cin >> n;
		odd=1%n;
		d=1;
		while (odd!=0){
			if (odd!=0){
				d+=1;
				odd=(odd*10)+1;
			}
			odd=odd%n;
		}
		cout << d << "\n";
	}
	return 0;
}