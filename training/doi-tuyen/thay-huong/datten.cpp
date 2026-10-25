#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("datten.inp","r",stdin);
#define fo freopen("datten.out","w",stdout);
#define ll long long

int t[2000]
int a , b;

int main() {
	boost;
	//fi;fo;
	int n , x; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> t[i]
	}
	int ma = INT_MIN , ans = 0;
	cin >> a >> b;
	for (int i = a ; i <= b ; i++) {
		for (int j = 1 ; j <= n ; j ++) {
			if (j % 2 != 0 && abs(i - t[j]) >= ma) {
				ans = i;
				ma = abs(i - t[i]);
			}
		}
	}
	cout << ans;
	return 0;
}