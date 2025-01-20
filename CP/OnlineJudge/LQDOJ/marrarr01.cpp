#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define ii pair<long long ,long long>

priority_queue <ii , vector <ii> , greater<ii>> pq , ans;

long long maxn = LLONG_MIN;

int main() {
	boost;
	long long t; cin >> t;
	long long count = 0 , n;
	while (t --){ 
		cin >> n;
		count ++;
		pq.push(ii(n,count));
		maxn = max(maxn,n);
	}

	//cout << pq.top().second << endl;
	vector <long long> v(3*maxn);
	v[0] = 0;
	v[1] = 1;
	for (long long i = 1 ; i <= (long long) maxn; i++) {
		v[2*i] = v[i];
		v[2*i + 1] = v[i] + v[i+1];
	} 

	long long maximum = LLONG_MIN;
	for (long long i = 0 ; i <= maxn ; i++) {
		maximum = max(maximum, v[i]);
		if (i == pq.top().first && !pq.empty()) {
			while (pq.top().first == i && !pq.empty()) {
				ans.push(ii(pq.top().second,maximum));
				pq.pop();
			}
		}
	}

	while(!ans.empty()) {
		cout << ans.top().second << endl;
		ans.pop();	
	}

	return 0;
}