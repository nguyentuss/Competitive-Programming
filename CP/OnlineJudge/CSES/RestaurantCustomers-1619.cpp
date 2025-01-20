#include <bits/stdc++.h>

using namespace std;

vector <int> a , b;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0 ; i < n ;i++) {
		int x , y; cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
	}
	sort(a.begin() , a.end()); 
	sort(b.begin() , b.end());
	int i , j , ans , c;	
	i = j = ans = c = 0;
	while(i < n) {
		if (a[i] < b[j]) {
			i++;
			c++;
		}
		else {
			c--;
			j++;
		}
		ans = max(ans , c);

	}
	cout << ans;
	return 0;
}