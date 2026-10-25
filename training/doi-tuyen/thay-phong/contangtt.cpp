#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e3 + 7)
#define inf (int) (1e9 + 7)

int f[MAX_N];
int trace[MAX_N];
int v[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> v[i];
		f[i] = 1;
		trace[i] = inf;
	}
	v[0] = inf;
	trace[0] = inf;

	for (int i = 1 ; i <= n ;i++) {
		for (int j = 1 ; j <= i ; j++) {
			if (v[i] > v[j]) {
				if (f[i] < (f[j] + 1)) {
					f[i] = f[j] + 1;
					trace[i] = j;
				}
				if (f[i] == (f[j] + 1) && v[trace[i]] > v[j]) {
					trace[i] = j;
				}
			}
		}
	}	
	int ans = -inf , minimum = inf, pos = 0;
	for (int i = 1 ; i <= n ;i++) {
		ans = max(ans , f[i]);
	}	
	for (int i = 1 ; i <= n ; i++) {
		if (ans == f[i] && minimum > v[i]) {
			minimum = v[i];
			pos = i;
		}
	}
	cout << ans << '\n';
	stack <int> write;
    while(1){
        write.push(pos);
        pos = trace[pos];
        if (pos == inf) break;
    }
    while(!write.empty()){
        cout << v[write.top()] <<" ";
        write.pop();
    }
	return 0;
}



// 1 2 3 10 4