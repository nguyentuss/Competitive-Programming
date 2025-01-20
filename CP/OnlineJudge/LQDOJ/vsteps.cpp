#include <iostream>
#include <map>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <vector> 
#include <tuple>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define modulo (long long) 14062008

vector <bool> check((int) 1e5 + 7);
vector <long long> dp((int) 1e5 + 7);

int main(){
	boost;

	int n , k , x; cin >> n >> k;
	for (int i = 1 ; i <= k ;i++){
		cin >> x;
		check[x] = true;
	}

	if (!check[1] && !check[2]) {
		dp[1] = 1LL;
		dp[2] = 1LL;
	}
	else if (check[1]) dp[1] = 0LL;
	else if (check[2]) dp[2] = 0LL;

	for (int i = 3 ; i <= n ; i++) {
		if (check[i]) dp[i] = 0;
		else dp[i] = (dp[i - 1]%modulo + dp[i - 2]%modulo)%modulo;
	}
	cout << dp[n];


	return 0; 
}