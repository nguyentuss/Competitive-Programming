#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

priority_queue<int , vector <int> , greater<int>> pq;

map <int , int> m;
vector <int> v;


int main() {
	boost;

	int n , k , x ; cin >> n >> k;

	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		v.push_back(x);
		pq.push(x);
		m[x] ++;
		if (i >= k) 
			m[v[i - k]] --;
		if (i >= k - 1) 
			while (true && !pq.empty()) {
				if (m[pq.top()] == 0) pq.pop();
				else {
					cout << pq.top() << endl;
					break;
				}
			}
	}

	return 0;
}