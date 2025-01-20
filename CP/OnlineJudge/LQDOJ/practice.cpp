#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define ii pair<long long , long long>

priority_queue <ii , vector <ii> , greater<ii>> pq;

int main() {	
	boost;

	long long n , c , a , b; cin >> n >> c;

	for (int i = 0 ; i < n; i++){
		cin >> a >> b;
		pq.push(ii(a,b));
	}

	long long ans = 0 ;
	while (true && !pq.empty()) {
		if (pq.top().first <= c) {
			c += pq.top().second;
			ans ++;
			pq.pop();
		}
		else break;
	}

	cout << ans;

	return 0;
}