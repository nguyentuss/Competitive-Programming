#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <limits.h>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define ii pair<double, double>
#define fi freopen("plants.inp","r",stdin);
#define fo freopen("plants.out","w",stdout);

vector <ii> v;
long long dp[7007] = {1};


int main(){
	boost;
	//fi;fo;
	int n , m ; cin >> n >> m;

	double a;
	double b;
	for (int i = 0 ; i < n ; i ++) {
		cin >> a >> b;
		v.push_back(ii(a,b)); 
	}
	//sort(v.begin() , v.end());
	

	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j < i ; j ++){
			if (v[i].second >= v[j].second) {
				dp[i] = max(dp[i],dp[j] + 1);
			}
		}
	}
	
	long long maximum = dp[0];
	for (int i = 1 ; i < n ; i++) maximum = max(maximum , dp[i]);

	cout << n - maximum;


	return 0;
}