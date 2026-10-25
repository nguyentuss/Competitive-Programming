#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (507)
#define MAX_R (int) (5007)
#pragma GCC optimize("Ofast")
#define lim (int) (1e6)

int n , m; 
int a[MAX_R][MAX_N];
int sum[MAX_R][MAX_N];
int f[MAX_R];
int cnt[2*lim + 7];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	freopen("balanrec.inp","r",stdin);
	freopen("balanrec.out","w",stdout);
	cin >> n >> m;
	if (n < m) {
		for (int i=1 ; i <= n ; i++)
          for (int j = 1 ; j <= m ; j++)
            {
            	cin>>a[j][n-i+1];
              	a[j][n - i + 1] = a[j][n - i + 1] ? 1 : -1;
            }
        swap(n , m);
	}
	else {
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 1 ; j <= m ;j++) {
				cin >> a[i][j];
				a[i][j] = a[i][j] ? 1 : -1;
			}
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			sum[i][j] = sum[i][j - 1] + a[i][j];
		}
	}
	int ans = 0;
	queue <int> q;
	for (int i = 1 ; i <= m ; i++) {
		for (int j = i ; j <= m ; j++) {
			int cursum = 0;
			for (int k = 1 ; k <= n ; k++) {
				cursum += sum[k][j] - sum[k][i - 1];
				if ((cursum + lim) == lim || cnt[cursum + lim]) {
					int matrix = (j - i + 1)*(k - cnt[cursum + lim]);
					ans = max(ans , matrix);
				}
				else {
					cnt[cursum + lim] = k;
					q.push(cursum);
				}
			}
			while (!q.empty()) {
				cnt[q.front() + lim] = 0;
				q.pop();
			}
		}	
	}
	cout << ans;
	return 0;
}