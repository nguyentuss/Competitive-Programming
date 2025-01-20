#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (2e5 + 7)
#define ii pair<int ,int>
#define f first
#define s second
#define inf (int) (1e9 + 7)

int n , m;
vector<ii> adj[MAX_N];
int get_other(int x) 
{
	int other;
	int sq = sqrt(x - 1);
	if (sq & 1) 
    { 
		if (abs(x - sq*sq) < abs(x - (sq + 1)*(sq + 1))) 
        {
			int dist = abs(x - sq*sq);
			other = (sq - 2) * (sq - 2) + dist - 1;
		} 
        else 
        {
			int dist = abs(x - (sq + 1)*(sq + 1));
			other = (sq - 1) * (sq - 1) + 1 - dist;
		}
	} 
    else 
    {
        if (abs(x - sq*sq) < abs(x - (sq + 1)*(sq + 1))) 
        {
			int dist = abs(x - sq*sq);
			other = (sq - 2) * (sq - 2) + dist - 1;
		} 
        else 
        {
			int dist = abs(x - (sq + 1)*(sq + 1));
			other = (sq - 1) * (sq - 1) + 1 - dist;
		}
    }
	return other;
}


signed main() {
    freopen("vuotnguc.inp","r",stdin);
    freopen("vuotnguc.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<ii> edges;
    vector<int> points;
    for (int i = 1 ; i <= m ; i++) {
        int x; cin >> x;
        int other = get_other(x);
        points.push_back(x); points.push_back(other);
        edges.push_back(ii(x , other));
    }
    points.push_back(n) , points.push_back(1);
	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.end());
	for (int a = 1; a < (int) points.size(); a++) 
    {
		adj[a - 1].push_back(ii(a, points[a] - points[a - 1]));
		adj[a].push_back(ii( a - 1, points[a] - points[a - 1] ));
	}
	for (ii p : edges) 
    {
		int p1 = lower_bound(points.begin(), points.end(), p.first) - points.begin();
		int p2 = lower_bound(points.begin(), points.end(), p.second) - points.begin();
		adj[p1].push_back(ii(p2, 1 )) , adj[p2].push_back(ii(p1, 1));
	}
    vector<int> dist(MAX_N , inf);
    priority_queue<ii , vector<ii> , greater<ii>> pq;   
    pq.push(ii(0 , 0));
    dist[0] = 0;
    while (!pq.empty()){ 
        ii u = pq.top();
        pq.pop();
        for (auto v : adj[u.s]) {
            if (dist[v.f] > u.f + v.s) {
                dist[v.f] = u.f + v.s;
                pq.push(ii(dist[v.f] , v.f));
            }
        }
    }
    for (int i = 0 ; i < points.size() ; i++) {
        if (points[i] == n) cout << dist[i];
    }


    return 0;
}