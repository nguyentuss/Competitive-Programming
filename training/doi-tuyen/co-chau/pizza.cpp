#include <bits/stdc++.h>
using namespace std;

struct seg 
{
	int x,y,s,sum;
	bool operator < (const seg &o) const 
	{
		return sum>o.sum;
	}
};

int k , r , m , n , ans , dq[105] , C[25],sum;
seg a[25], b[105];
vector <int> adj[25];

bool check(int i,int j) 
{
	int x=b[i].x-a[j].x;
	int y=b[i].y-a[j].y;
	return (x*x+y*y<=r*r);
}

void backtr(int x,int last,int cnt) 
{
	if (cnt==sum) 
	{
		cout << sum;
		exit(0);
	}
	if (x == k+1) 
	{
		ans = max(ans,cnt);
		return ;
	}
	for (int i = last+1 ; i <= m ; i ++)
	if (!C[i]) 
	{
		C[i]=1;
		for (auto j : adj[i])
			if (dq[j]==0) cnt += b[j].s , dq[j]=x;
		backtr(x+1,i,cnt);
		C[i]=0;
		for (auto j : adj[i])
			if (dq[j]==x) cnt -= b[j].s , dq[j]=0;
	}
}

int main() 
{
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("pizza.inp","r",stdin);
 	freopen("pizza.out","w",stdout);
	cin >> k >> r >> m;
	for (int i = 1 ; i <= m ; i++)  
		cin >> a[i].x >> a[i].y;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)  
	{
		cin >> b[i].x >> b[i].y >> b[i].s;
		int checked = 0;
		for (int j = 1 ; j <= m; j++) 
			if (check(i,j)) 
			{
				adj[j].push_back(i);
				a[j].sum += b[i].s;
				checked=1;
			}
		if (checked) sum+=b[i].s;
	}
	sort(a + 1 , a + m + 1);
	backtr(1,0,0);
	cout << ans;
	return 0;
}