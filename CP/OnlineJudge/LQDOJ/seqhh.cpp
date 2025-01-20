#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int v[100006] , sum[100006];
map <int , int> m;

int main(){
	boost;

	int n , k; cin >> n >> k;

	sum[0] = 0;

	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
		m[sum[i]] ++;
	}

	//for (int i = 1 ; i <= n ; i++) cout << sum[i] << " " ;

	int ans = 0;
	for (int i = 1 ; i <= n ; i++) 
		ans += m[(k - v[i]) + sum[i]];
	cout << ans;
	
	return 0;
}