#include <bits/stdc++.h>
using namespace std;

double cross(point p1,point p2,point p0){
    return ((p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x))*0.5;
}

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	freopen("CAKE.inp","r",stdin);
	freopen("CAKE.out","w",stdout);
	int n;
	cin >> n;
	vector<pair<int,int>> p(n);
	for (int i=0;i<n;i++) cin >> p[i].first >> p[i].second;
	vector<vector<int>> s(n,vector<int>(n));
	int res=0;
	for (int i=0;i<n;i++) 
	{
		int k=(i+3)%n;
		for (int j=(i+2)%n;j!=(i+n-1)%n;j=(j+1)%n) 
		{
			if (k==j) k=(++k)%n;
			s[i][j]=check(i,j,k);
			while ((k+1)%n!=i&&check(i,j,k)<=check (i,j,(k+1)%n)) 
			{
				k=(k+1)%n;
				s[i][j]=check(i,j,k);
			}
			res=max(res,s[i][j]+s[j][i]);
		}
	}
	cout << fixed << setprecision(1) << res;
	return 0;
}