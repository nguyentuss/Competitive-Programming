#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (107)
#define MAX_VAL (int) (2e6 + 7)

int a[MAX_N];
int visited[MAX_VAL];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t; 
	while (t--) {
		int n , k; cin >> n >> k;
		for (int i = 1 ; i <= n ; i++) 
			cin >> a[i];
		memset(visited , -1 , sizeof visited);
		queue <int> q;
		q.push(1);
		visited[1] = 0;
		while (!q.empty()) {
			int val = q.front();
			q.pop();
			for (int i = 1 ; i <= n ; i++) {
				int newVal = val*a[i];
				if (newVal > k || visited[newVal] != -1) continue;
				visited[newVal] = visited[val] + 1;
				q.push(newVal);
			}
		}
		if (visited[k] == -1) cout << "Impossible" << '\n';
		else cout << visited[k] << '\n';
	}
	return 0;
}