#include <bits/stdc++.h>

using namespace std;


const int maxn = 200;
int a[maxn] , dem = 0;


int main(){

	freopen("bai23.inp","r",stdin);
	freopen("bai23.out","w",stdout);

	int n; cin >> n ;

	for (int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for (int i = 1 ; i <= n ; i++){

		for (int j = i + 1; j <= n ; j++)
		{
			if (a[i] == a[j]) dem ++;
		}
	
	}
	cout << dem << endl;
	for (int i = 1 ; i <= n ; i++){

		for (int j = i + 1; j <= n ; j++)
		{
			if (a[i] == a[j]) 
					cout << i << " " << j << endl;
		}

	}

	return 0;
}