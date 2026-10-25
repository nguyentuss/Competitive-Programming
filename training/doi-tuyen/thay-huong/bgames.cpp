#include <bits/stdc++.h>
using namespace std;

const int lm=3e5+5;
int n, k;
int a[lm];
map <int,int> c;

int count(int x) 
{
	int res=0;
	int t=x-k;
	for (int i=1;i*i<=t;i++) 
	{
		if (x%i==k) res+=c[i];
		if (i*i!=t&&x%(t/i)==k) res+=c[t/i];
	}
	if (k==0) res-=1;
	return res;
}

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("bgames.inp","r",stdin);
	freopen("bgames.out","w",stdout);
	cin >> n >> k;
	int countk=0;
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i];
		c[a[i]]+=1;
		if (a[i]>k) countk+=1;
	}
	for (int i=1;i<=n;i++) 
	{
		if (a[i]<k) cout << 0 << " ";
		else if (a[i]==k) cout << countk << " ";
		else cout << count(a[i]) << " ";
	}
	return 0;
}