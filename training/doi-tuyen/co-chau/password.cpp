#include <bits/stdc++.h>

using namespace std;

char maxth[] = {'z' , 'y'};
char maxh[] = {'Z' , 'Y'};
char maxs[] = {'9' , '8'};
char mins[] = {'0' , '1'};
char minth[] = {'a' , 'b'};
char minth[] = {'A' , 'B'};

void calc(int last , int status , int len) {
	int cnt = 0;
	int mod = 3 , dem = 0;
	while (cnt != last) {
		cnt++;
		if (status == 1) cout << mins[(dem++)%mod];
		if (status == 2) cout << minh[(dem++)%mod];
		if (status == 3) cout << minth[(dem++)%mod];
		if (status == 4) cout << maxth[(dem++)%mod];
		if (status == 5) cout << maxh[(dem++)%mod];
		if (status == 6) cout << maxs[(dem++)%mod];
	} 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	//freopen("password.inp","r",stdin);
	//freopen("password.out","w",stdout);
	int n , a , b , c; cin >> n >> a >> b >> c;
	calc(n - (b + c) , 1 , a);
	calc(b , 2 , a);
	calc(c , 3 , b);
	calc(n - (a + c) , 4 , a);
	calc(b , 5 , b);
	calc(c , 6 , c);


	return 0;
}