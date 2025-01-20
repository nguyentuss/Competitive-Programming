#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int t;
int a[100][100];

bool check(int a,int b,int c) {
	return 2*b-c==a;
}

int main() 
{
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("AC3.INP","r",stdin);
	freopen("AC3.OUT","w",stdout);
	cin >> t;
	while (t--) 
	{
		int ans=0;
		for (int i = 1; i <= 3;i++) cin >> a[1][i];
		cin >> a[2][1] >> a[2][3];
		for (int i = 1 ; i <= 3 ; i++) cin >> a[3][i];
	
		if (check(a[1][1],a[1][2],a[1][3])) ans++;
		if (check(a[3][1],a[3][2],a[3][3])) ans++;
		if (check(a[1][1],a[2][1],a[3][1])) ans++;
		if (check(a[1][3],a[2][3],a[3][3])) ans++;
		int cnt=0;
		for (int x=-10;x<=10;x++) 
		{
			int d=0;
			if (check(a[1][1],x,a[3][3])) d+=1;
			if (check(a[1][2],x,a[3][2])) d+=1;
			if (check(a[1][3],x,a[3][1])) d+=1;
			if (check(a[2][1],x,a[2][3])) d+=1;
			cnt=max(cnt,d);
		}
		cout << ans + cnt << '\n';
	}
	return 0;
}