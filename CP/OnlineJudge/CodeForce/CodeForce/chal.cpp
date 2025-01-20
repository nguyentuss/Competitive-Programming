#include <iostream>
using namespace std;
#define maxa int (10e5)
#define maxnm int (10e3)
int b[maxnm][maxnm], a[maxnm][maxnm];
bool check[maxa + 1] = {false};
int main () {
	ios::sync_with_stdio (false); cin.tie (0);
	int m, n; cin >> m >> n;
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++) 
			cin >> a[i][j];
	for (int i = 2; i <= maxa; i++) check[i] = true;
  	for (int i = 2; i <= maxa; i++) 
    	if (check[i] == true) 
      		for (int j = 2 * i; j <= maxa; j += i) check[j] = false;
  	for (int i = 0; i < m; i++) 
  		for (int j = 0; j < n; j++) 
  			while (check[a[i][j]] == false) {
  				a[i][j]++;
  				b[i][j]++;
  			}
	long long res = 1e9, k, l;
  	for (int i = 0; i < m; i++){
  		k = 0;
  		for (int j = 0; j < n; j++) 
  			k += b[i][j];
  		res = min (res, k);
  	}
  	for (int i = 0; i < m; i++){
  		k = 0;
  		for (int j = 0; j < n; j++) 
  			k += b[j][i];
  		res = min (res, k);
  	}
  	cout << res;
	return 0;
}