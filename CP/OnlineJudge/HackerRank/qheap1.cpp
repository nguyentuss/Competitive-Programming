#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

priority_queue<int , vector<int> , greater <int>> pq;
map <int , bool> m;


int main() {
	boost;

	int num;
	int n , a; cin >> n;
	for (int i = 1 ; i <= n; i++) {
		cin >> num;
		if (num == 1) {
			cin >> a;
			pq.push(a);
		}
		else if (num == 2) {
			cin >> a;
			m[a] = true;
		}
		else if (num == 3) {
			if (m[pq.top()] == false) cout << pq.top() << endl;
			else 
				while (true) {
					if (m[pq.top()] == true) pq.pop();
					else {
						cout << pq.top() << endl;
						break;
					}
				}
		}
	}

	return 0;
}