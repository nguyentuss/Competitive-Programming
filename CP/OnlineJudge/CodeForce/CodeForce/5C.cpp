#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 7;
string s;
int c[MAX_N], f[MAX_N] , pos , maxi , cnt=1;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> s;
	int n= s.size();
	for(int i = 0 ; i < n ; i++)
	{
		if(s[i]=='(') c[++pos] = i;
		else 
		if(pos){
			f[i] = i - c[pos] + 1 + f[c[pos--]-1];
			if(f[i] == maxi) cnt++;
			if(f[i] > maxi) {
				maxi = f[i];
				cnt = 1;
			}
		}
	}
	cout << maxi << " " << cnt;
}