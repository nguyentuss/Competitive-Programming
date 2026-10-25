#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

int n , m;
int x[20] , a[20];
int ans = 0;

void xuli() {
	int sum1 = m , sum2 = 0;
	for (int i = 1 ; i <= n ; i++) {
		if (x[i] == 1) sum1 += a[i];
		if (x[i] == 2) sum2 += a[i];
	}
	if (sum1 == sum2) {
		/*cout << m << " ";
		for (int i = 1 ; i <= n ; i++) {
			if (x[i] == 1)
				cout << a[i] << " ";
		}
		cout << "|";
		for (int i = 1 ; i <= n ; i++) {
			if (x[i] == 2) {
				cout << a[i] << " ";
			}
		}
		cout << '\n';*/
		ans++;
	}
}

int quaylui(int i) {
	// ta chọn tập nghiêm với j = 0 là kh chọn 
	// j = 1 là chọn cho cân 1 , j = 2 là chọn cho cân 2
	for (int j = 0 ; j <= 2 ; j++){
		x[i] = j;
		if (i == n) xuli();
		else quaylui(i + 1);
	} 
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("can.inp","r",stdin);
	//freopen("can.out","w",stdout);
	//freopen("test.inp","r",stdin);
	//freopen("test.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	quaylui(1);
	if (ans == 0) cout << -1;
	else {
		cout << ans;
	}
	return 0;
}