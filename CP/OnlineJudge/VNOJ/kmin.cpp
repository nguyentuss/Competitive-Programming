#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#define ii pair<int ,int>
#define iii pair<int, ii>

int m , n , k , x;
vector <int> a , b;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n >> k;
	for (int i = 0 ; i < m ; i++) {
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		b.push_back(x);
	}
	sort(a.begin() , a.end());
	sort(b.begin() , b.end());
	priority_queue <iii , vector <iii> , greater<iii>> pq;
	for (int i = 0 ; i < (int) a.size() ; i++) 
		pq.push(iii(a[i] + b[0] , ii(i , 0)));
	vector <int> ans;
	while (!pq.empty()) {
		int l = pq.top().second.first , r = pq.top().second.second;
		ans.push_back(pq.top().first);
		pq.pop();
		if ((int) ans.size() == k) {
			for (int i = 0 ; i < (int) ans.size() ; i++) 
				printf(ans[i] << '\n';
			return 0;
		} 
		while (r < n) {
			r ++;
			if (a[l] + b[r] > pq.top().first) {
				pq.push(iii(a[l] + b[r] , ii(l , r)));
				break;
			}
			else ans.push_back(a[l] + b[r]);
			if ((int) ans.size() == k) {
				for (int i = 0 ; i < (int) ans.size() ; i++) 
					cout << ans[i] << '\n';
				return 0;
			} 
		}
	}

	return 0;
}