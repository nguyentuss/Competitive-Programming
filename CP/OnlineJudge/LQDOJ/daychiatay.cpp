#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int x;
vector <int> v;
queue <int> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	int n , t , c; cin >> n >> t >> c;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	int counted = 0;
	int ans = 0;

	for (int i = 0 ; i < n ; i++) {
		if (v[i] <= t) {
			q.push(v[i]);
			counted ++;
			if (counted == c) {
				q.front();
				counted --;
				ans ++;
			}
		}
		else {
			counted = 0;
			q.empty();
		} 
	}
	cout << ans;
	return 0;
}