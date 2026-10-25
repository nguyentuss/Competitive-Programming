#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fi freopen("SSEARCH.inp","r",stdin);
#define fo freopen("SSEARCH.out","w",stdout);
#define ll long long
int a , n , x;
int v[(int) 1000006];

int main() {
	boost;
	fi;fo;
	cin >> n >> x; 
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
	}
	for (int i = 1 ; i <= n; i++) {
		if (v[i] == x) {
			cout << i;
			return 0;
		}
	}
	//cout << FindPos(x);
	cout << -1;
	return 0;
}