#include <bits/stdc++.h>

using namespace std;


char a[200];
int n, x = 0 , y = 0;


int main(){
	freopen("bai13.inp","r",stdin);
	freopen("bai13.out","w",stdout);
	
	cin >> n;

	for (int i = 1;i<=n;i++) cin >> a[i];
	for (int i = 1;i<=n;i++){
		if (a[i] == 'G') y+=1;
		else if (a[i] == 'B') y-=1;
		else if (a[i] == 'L') x-=1;
		else if (a[i] == 'R') x+=1;
	}
	cout << x << " " << y;
	return 0;
}