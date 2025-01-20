#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <limits.h>

using namespace std;

#define BOOST ios::sync_with_stdio(false); cin.tie(NULL); 
//#define fi freopen("move12.inp","r",stdin);
//#define fo freopen("move12.out","w",stdout);
#define ii pair <int,int>

//
vector <ii> v;
int n, c, t;

//

bool check(int x , vector <ii> &v) {
	int left, right , count = 0; 
	vector <ii> arr;
	priority_queue <int , vector<int> , greater<int>> pq;
	bool checknum = true;
	for (int i = 0; i < n ; i++){
		left = v[i].first - (x / v[i].second);
		if (left <= 1) left = 1;
		right = v[i].first + (x / v[i].second);
		if (right >= n) right = n;
		arr.push_back(ii(left,right));
	}	
	sort(arr.begin(),arr.end());

	int pos = 0;
	for (int i = 1 ; i <= n ; i ++) {
		while (checknum) {
			if (i >= arr[pos].first && i <= arr[pos].second){
				pq.push(arr[pos].second);
				if (pos <= n) pos ++;
			}
			else break;
		}
		if (!pq.empty()) {
			if (i <= pq.top())
				count ++;
			pq.pop();
		}

	}
	if (count == n) return true;
	else return false;
}

int main() {
	BOOST;
	//fi;fo;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c >> t;
		v.push_back(ii(c, t));
	}
	long long mid , l = 0 , r = 1000000007 , ans = LLONG_MAX ;
	while (l <= r) {
		mid = (l + r)/2;
		//cout << mid << endl;
		if (check(mid , v)) {
			r = mid - 1;
			ans = min(ans,mid);
		}
		else l = mid + 1;

	}
	cout << ans;

	return 0;
}