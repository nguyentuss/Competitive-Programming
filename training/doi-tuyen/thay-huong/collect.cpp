#include <bits/stdc++.h>

using namespace std;

#define iii pair<int , pair<int , int>>
#define iv pair <int , iii>
#define ii pair<int , int>
struct edge
{
  int x,y,z,i,j,k;
  /*bool cmp(edge &u,edge &v) 
  {
    return u.x<v.x;
  }*/
  bool cmp(edge &u,edge &v) 
  {
    return u.x<v.x||(u.x==v.x&&u.y<v.y)||(u.x==v.x&&u.y==v.y&&u.z<v.z);
  }
};
bool cmp(edge &u , edge &v) {
	return u.x<v.x||(u.x==v.x&&u.y<v.y)||(u.x==v.x&&u.y==v.y&&u.z<v.z);
}


int k , a , b , c , x , y , z;
int Z , M , S , z0 , m0 , s0;
vector <edge> v;
vector <edge> ans;
bool C[5][5][5];

void BFS() 
{
	queue <edge> q;
	q.push({Z , S , M , 0});
	C[Z][S][M]=1;
	while (q.size()) 
	{
		x=q.front().x,y=q.front().y,z=q.front().z;
		int time=q.front().i;
		q.pop();
		if (z0<=x&&s0<=y&&m0<=z) 
		{
			ans.push_back({x,y,z,time});
			continue;
		}
		if (time==k) continue;
		for (auto t:v) 
		{
			int i=x-t.x+t.i,j=y-t.y+t.j,k=z-t.z+t.k;
			if (x>=t.x&&i<=4&&y>=t.y&&j<=4&&z>=t.z&&k<=4&&!C[i][j][k]) 
			{
				C[i][j][k]=1;
				q.push({i,j,k,time+1});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
//	freopen("collect.inp","r",stdin);
//	freopen("collect.out","w",stdout);
	cin >> k >> Z >> S >> M >> z0 >> s0 >> m0;
	while (cin >> a >> b >> c >> x >> y >> z) 
		v.push_back({a , b , c , x , y  , z});
	BFS();
	if (!ans.size()) return (cout << -1,0);
	cout << ans.size() << '\n';
	sort(ans.begin() , ans.end() ,cmp);
	for (edge e : ans)
		cout << e.x << " " << e.y << " " << e.z << " " << e.i << '\n';
	return 0;
}