#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (4e4 + 7)
#define inf (int) (1e9 + 7)

int x[MAX_N] , y[MAX_N];
int a[MAX_N] , b[MAX_N];
int n , k , ans = inf;

void calc(int posx , int posy) {
	int tmp = 0;;
	for (int i = 1; i <= k ; i++) {		
		tmp = max(tmp , min(abs(a[i] - posx) , abs(b[i] - posy)));
	}
	ans = min(ans , tmp);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("roads.inp","r",stdin);
	freopen("roads.out","w",stdout);
	//freopen("test.inp","r",stdin);
	cin >> n >> k;
	for (int i = 1 ; i <= k ; i++) {
		cin >> a[i] >> b[i];
		x[i] = a[i] , y[i] = b[i];
	}
	sort(x + 1 , x + 1 + k);
	sort(y + 1 , y + 1 + k);
	for (int i = 1 ; i <= k ; i++) {
		calc(x[i] , y[i]);
	}
	/*cout << x[k/2 + 1] << " " << y[k/2 + 1] << '\n';
	calc(x[k/2 + 1] , y[k/2 + 1]); 
	if (k % 2 == 0) {
		cout << x[k/2] << " " << y[k/2]; 
		calc(x[k/2] , y[k/2]);
	}*/
	cout << ans;

	return 0;
}