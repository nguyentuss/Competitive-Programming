#include <bits/stdc++.h>

using namespace std;

int n , x , y , z;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("FOOD.inp","r",stdin);
	freopen("FOOD.out","w",stdout);
	cin >> n >> x >> y >> z;
	//cout << n << " " << x << " " << y << " " << z;
	cout << max(0 , x + y - (n - z));
	return 0;
}