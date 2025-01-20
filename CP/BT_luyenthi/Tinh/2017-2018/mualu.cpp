#include <bits/stdc++.h>

using namespace std;

vector <int> graph[100005];
int dem = 0;
int n , m , x;

void BFS()
	{
		bool visit[100005] = {false};

		for (int i = 1 ; i <= n ; i++)
			{
				if (!visit[i]) {
					queue <int> q;
					visit[i] = true;
					q.push(i);
					while (!q.empty())
					{
						int u = q.front();
						q.pop();
						for (int j = 0 ; j < graph[u].size() ; j++)
						{
							int v = graph[u][j];
							if ((!visit[v]) ){
								//cout << u << " " << v << " " << c[u][v] << endl;
								visit[v] = true;
								q.push(v);
							}

						}
					}
					dem++;
				}
			}
	}



int main()
{
	ios::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL);

	//freopen("mualu.inp","r",stdin);
	//freopen("mualu.out","w",stdout);

	cin >> n >> m >> x;
	for (int i = 0 ; i < m ; i++)
		{
			int u , v , c;
			cin >> u >> v >> c;
			if (c < x) continue;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
	//cout << graph[1].size();
	//for (int i = 1 ; i <= n ; i++){
	//	for (int j = 0 ; j < graph[i].size() ; j++)
	//		cout << graph[i][j] << " ";
	//	cout << '\n';
	//}
	BFS();
	cout << dem;
	return 0;
}