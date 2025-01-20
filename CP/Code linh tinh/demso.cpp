#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
int n , a[maxn] = {0};

int main(){
	freopen("demso.inp", "r", stdin);
	freopen("demso.out", "w", stdout);
	cin >> n;
	int tam;
	for (int i=1; i<=n;i++){
		cin >> tam;
		a[tam + 50] += 1;
	}
	for (int i = 0; i <=101;i++){
		if (a[i]>0){
			cout << (i-50) << ": " << a[i] << endl;
		}
	}
	return 0;
}