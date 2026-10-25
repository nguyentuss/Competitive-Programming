#include <bits/stdc++.h>
using namespace std;

#define MAX_N (int) (1e5 + 7)

vector <int> adj[MAX_N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin >> n >> k;
	for (int i = 1 ; i <= k ; i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector <bool> vis(n);
	long long res = 0; 
	for (int i = 0; i < n ; i++)
		if (!vis[i])
		{
			vis[i]=1;
			int d=1;
			queue <int> q;
			q.emplace(i);
			while (q.size())
			{
				int u=q.front();
				q.pop();
				for (int v:adj[u])
					if (!vis[v])
					{
						vis[v]=1;
						d++;
						q.emplace(v);
					}
			}
			res += d*(n-d);
		}
	cout << res/2;
}