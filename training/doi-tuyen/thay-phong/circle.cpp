#include <bits/stdc++.h>
using namespace std;

struct seg
{
	double x,y,l;
};

bool cmp(seg a,seg b) {
	return a.l<b.l;
}
int n;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector <seg> a(n), b(n);
	for (int i = 0 ; i < n ; i++) 
	{
		cin >> a[i].x >> a[i].y;
		a[i].l=sqrt((a[i].x-0)*(a[i].x-0)+(a[i].y-0)*(a[i].y-0));
	}
	for (int i = 0 ; i < n ; i++) 
	{
		cin >> b[i].x >> b[i].y;
		b[i].l=sqrt((b[i].x-0)*(b[i].x-0)+(b[i].y-0)*(b[i].y-0));
	}
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	for (int i = 0 ; i < n ; i++) 
	{
		if (max(a[i].l,b[i].l)<min(a[i+1].l,b[i+1].l)) 
		{
			cout << fixed << setprecision(6) <<  max(a[i].l,b[i].l);
			return 0;
		}
	}
	cout << fixed << setprecision(6) << max(a[n-1].l,b[n-1].l);
	return 0;
}