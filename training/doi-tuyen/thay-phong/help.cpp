#include<bits/stdc++.h>
using namespace std;

long double a,b,c,v0,v1,v2,ans;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	cout.tie(NULL);
	cin>> a >> b >> c >> v0 >> v1 >> v2;
	ans= a/v0 + c/v1 + b/v2;

	ans=min(ans, b/v0 +c/v1+ a/v2);
	ans=min(ans, a/v0 + a/v1+ b/v0 +b/v1);

	ans=min(ans, a/v0 + c/v0+ c/v1+ a/v2);
	ans=min(ans, b/v0 + c/v0+ c/v1+ b/v2);

	ans=min(ans, b/v0+ b/v1+ a/v0+ c/v0+ b/v1);
	ans=min(ans, b/v0+ b/v1+ a/v0+ c/v0+ a/v1);

	ans=min(ans, a/v0 + a/v1+ a/v0+ c/v0+ c/v1+ a/v1);
	ans=min(ans, a/v0 + a/v1+ b/v0+ c/v0+ c/v1+ b/v1);

	ans=min(ans, b/v0+ b/v1+ a/v0+ c/v0+ c/v1+ a/v1);
	ans=min(ans, b/v0+ b/v1+ a/v0+ c/v0+ c/v1+ b/v1);
	ans=min(ans, b/v0 + b/v1+ b/v0+ c/v0+ c/v1+ b/v1);

 	cout<<fixed<<setprecision(5)<<ans;

	return 0;
}