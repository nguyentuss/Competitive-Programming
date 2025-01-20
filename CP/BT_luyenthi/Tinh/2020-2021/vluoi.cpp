#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define ii pair<int,int>
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
int n , m , a[1001][1001] , index[1001][1001];
bool visit[1001][1001] = {false};
vector <ii> v[1001];

bool check(int u , int v){
	return u >= 1 && u <= m && v >= 1 && v <= n;
}

void BFS(int start){
	queue <ii> pos;
	queue <int> q;
	queue <int> khac;
	khac.push(start);
	pos.push(ii(1,1));
	visit[1][1] = true;
	index[1][1] = 1;
	int cntidx = 0;
	int cnt[10004] = {1};

	while (!khac.empty()){
		cntidx ++;
		int x = khac.front();
		q.push(khac.front());
		khac.pop();
		vector <int> vtmp(n+1,0);
		while (!q.empty()){
			pair <int,int> tmp = pos.front();
			int i = tmp.first;
			int j = tmp.second;
			pos.pop();	
			q.pop();

			for (int dir = 0 ; dir < 4 ;dir++){
				int u = tmp.first + dx[dir];
				int v = tmp.second + dy[dir];
				if (check(u,v) && a[i][j] == a[u][v] && !visit[u][v]) {
					q.push(a[u][v]);
					pos.push(ii(u,v));
					visit[u][v] = true;
					index[u][v] = cntidx;
					cnt[index[u][v]] ++;
				}
				else 
					if (check(u,v) && a[i][j] != a[u][v] && !visit[u][v]) {
						
						if (!index[u][v]) khac.push(a[u][v]);
						else
							vtmp.push_back(index[u][v]);
					}
			}
			
			sort(vtmp.begin(),vtmp.end());
			int num = 0;
			for (int i = 0 ; i < vtmp.size() ; i ++)
			{
				num ++;
				if (num == 1) {
					cout << cnt[cntidx]*x << endl;
					v[cntidx].push_back(ii(cnt[cntidx]*x,vtmp[i]));
					v[vtmp[i]].push_back(ii(cnt[cntidx]*x,cntidx));
				}
				if (vtmp[i] != vtmp[i+1]) num = 0;
			}


		}
	}

	/*for (int i = 0 ; i <= 10 ; i++)
		for (auto it : v[i])
			cout << it.first << " " << it.second << '\n';
	*/
}

int main(){

	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("vluoi.inp","r",stdin);
	freopen("vluoi.out","w",stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++){
			cin >> a[i][j];
		}

	BFS(a[1][1]);
	

	return 0;
}