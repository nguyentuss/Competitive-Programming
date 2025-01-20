#include <iostream>
using namespace std;

int  a[101][101] = {0};
int m , n;

bool kt(int i , int j){
	int k;
	bool tdong = true , ttay = true , tnam = true, tbac = true;
	for (k = j+1 ; k <= n ; k++)
		if (a[i][k] > a[i][j]) {
			tdong = false;
			break;
		}
	for (k = j-1 ; k >= 1; k--)
		if (a[i][k] > a[i][j]) {
			ttay = false;
			break;
		}
	for (k = i+1 ; k <= m; k++)
		if (a[k][j] > a[i][j]) {
			tnam = false;
			break;
		}
	for (k = i-1 ; k >= 1; k--)
		if (a[k][j] > a[i][j]) {
			tbac = false;
			break;
		}
	return (tbac || tnam || tdong || ttay);
}

int main(){

	freopen("bai15.inp","r",stdin);
	freopen("bai15.out","w",stdout);
	int x,y,dem; cin >> m >> n;

	for (x = 1 ; x <= m ; x++)
		for (y = 1; y <= n ; y++)
			cin >> a[x][y];
	dem = 0;
	for (x = 1  ; x <= m ; x++)
		for (y = 1 ; y <= n ; y++)
			if (kt(x,y)) dem++;

	cout << dem ;

	return 0;

}