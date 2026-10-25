#include<bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)

int s , pos , v[MAX_N] , n , k;
bool check[MAX_N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for(long i=1; i<=k; i++){
		cin >> s;
		for (int j = 1 ; j <= 2*s ; j++) 
			cin >> v[j];
		int win; cin >> win;
		if(s == 1){
			if (win == 1) pos = v[2];
			if (win == 2) pos = v[1];
		} 
		if(win == 0)
			for (int j = 1 ; j <= 2*s ; j++) check[v[j]] = true;
		else 
			if(win == 1)
				for(int j=1; j<=s; j++) check[v[j]]=true;
		else 
			if(win == 2)
				for(int j = s + 1; j <= 2*s; j++) check[v[j]]=true;
	}
	if (pos != 0) cout << pos;
	else {
		int cnt = 0;
		for(int i = 1 ; i <= n ; i++){
			if(!check[i]) {
				cnt++; 
				pos = i;
			}
		}
		if(cnt == 1) cout << pos;
		else cout << 0;
	}
	return 0;
}