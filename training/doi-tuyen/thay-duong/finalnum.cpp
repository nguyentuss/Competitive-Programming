#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using namespace std;

string st;
long long total = 0;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("finalnum.inp","r",stdin);
	freopen("finalnum.out","w",stdout);
	cin >> st;

	while ((int) st.size() != 1) {
		total = 0;
		for (int i = 0 ; i < (int) st.size() ; i++)
			total += (int) st[i] - '0';
		ostringstream chuyen;
		chuyen << total;
		st = chuyen.str();
	} 
	cout << st;
	
	return 0;
}