#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int n , c , mid , ans = 1e9;

bool check(long long x , vector <int> &v){
	int find = v[0] , numcow = 1;
	//cout << x << endl;
	for (int i = 1 ; i < (int) v.size() ; i ++) {
		//cout << numcow << endl;
		if (v[i] - find >= x) {
			numcow ++;
			find = v[i] ;
		}
		if (numcow >= c) return true;
	}
	return false;
}

int main() {
	boost;
	//freopen("aggrcow.inp","r",stdin);
	//freopen("aggrcow.out","w",stdout);
	int t , a; cin >> t;
	for (int j = 1 ; j <= t ; j ++) {
		cin >> n >> c;
		vector <int> v;
		for (int i = 1 ; i <= n ; i++){
			cin >> a;
			v.push_back(a); 
		}
		sort(v.begin(),v.end());
		long long l = 1, r = 1000000007;
		while(l <= r)
    	{	
        	mid = (l + r) / 2;
        	if(check(mid , v))
        	{
        		//cout << mid << endl;
            	l = mid + 1;
            	ans = mid;
        	}
        	else r = mid - 1;
    	}
    	cout << ans << endl;
	
	}
	return 0;
}