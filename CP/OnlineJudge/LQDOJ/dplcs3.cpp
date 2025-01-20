	#include <iostream>
	#include <cmath>
	#include <algorithm>
	#include <vector>


	#pragma GCC optimize("Ofast")
	#define MAX_M (int) (5e3 + 7)
	#define MAX_N (int) (2e4 + 7)
	#define inf (int) (5e6 + 7)

	using namespace std;

	char a[MAX_N];
	char b[MAX_M];
	string temp;
	vector <int> v[140];
	int m , n , x;
	int dp[MAX_M][MAX_M];

	void init() {
	    for (int i = 1 ; i <= 140 ; i++) v[i].clear();
	    for (int i = 0 ; i <= n; i++) 
	        for (int j = 0 ; j <= n; j++) 
	            dp[i][j] = inf;
	}


	int main(){

	        cin >> temp;
	        for (int i = 0 ; i < (int) temp.size() ; i++) 
	        	a[i + 1] = temp[i];
	        m = temp.size();
	    	cin >> temp;
	    	for (int i = 0 ; i < (int) temp.size() ; i++) 
	    		b[i + 1] = temp[i];
	    	n = temp.size();
	        init();
	        for (int i = 1 ; i <= m ; i++) 
	            v[(int) a[i]].push_back(i);
	        for (int i = 0 ; i <= n ; i++) 
	            dp[i][0] = 0;
	        for (int i = 0 ; i < n; i++) { 
	            for (int j = 0 ; j <= n ; j++) {
	                if (dp[i][j] != inf) {
	                    dp[i + 1][j] = min(dp[i + 1][j] , dp[i][j]);
	                    int l = 0 , r = (int) v[(int) b[i +1]].size() - 1, pos = inf;
	                    while (l <= r) {
	                        int mid = (l + r)/2;
	                        if (v[(int) b[i + 1]][mid] > dp[i][j]) {
	                            pos = min(pos , v[(int) b[i + 1]][mid]);
	                            r = mid - 1;
	                        }
	                        else l = mid + 1;
	                    }
	                    dp[i + 1][j + 1] = min(dp[i+1][j+1],pos);
	                }
	            }
	        }
	        int ans = 0;
	        for (int j = 0 ; j <= n ; j++) 
	        if (dp[n][j] <= m) ans = max(ans , j);
	        cout << ans << endl;  
	    
	    return 0;
	}