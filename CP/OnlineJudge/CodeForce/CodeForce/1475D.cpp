#include <bits/stdc++.h>

using namespace std;

vector <int> type1 , type2;
vector <int> a , b;
vector <long long> sum1(200007 , 0);
vector <long long> sum2(200007 , 0);
int n ,m , x;
int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	int t; cin >> t;
	while (t --) {
		type1.clear(); type2.clear(); b.clear(); a.clear();
		cin >> n >> m;
		for (int i = 0 ; i < n ; i++){ 
			cin >> x; 
			a.push_back(x);
		}
		for (int i = 0 ; i < n ; i++) {
			cin >> x;
			b.push_back(x);
			if (x == 1) type1.push_back(a[i]);
			else type2.push_back(a[i]);
		} 
		sort(type2.begin() , type2.end() , greater<int>());
		sort(type1.begin() , type1.end() , greater<int>());
		sum1[0] = 0 , sum2[0] = 0;
		for (int i = 1 ; i <= type1.size() ; i++) 
			sum1[i] = sum1[i - 1] + type1[i - 1];
		for (int i = 1 ; i <= type2.size() ; i++) 
			sum2[i] = sum2[i - 1] + type2[i - 1];
		int ans = INT_MAX;
		for (int x = 0 ; x <= (int) type2.size() ;x++){
			long long temp = m - sum2[x];
			if (temp <= 0) {
				ans = min(ans , 2*x);
				break;
			}
			int l = 0 , r = type1.size();
			
			while (l <= r) {
				int mid = (l + r)/2;	
				if (sum1[mid] >= temp) {
					r = mid - 1;
					ans = min(ans , 2*x + mid);
				}
				else l = mid + 1;
			} 
		}
		if (ans == INT_MAX) cout << -1 << '\n';
		else cout << ans << '\n';
	}
		
	return 0;
}