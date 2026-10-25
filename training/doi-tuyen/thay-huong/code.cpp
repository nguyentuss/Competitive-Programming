#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>


using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("code.inp","r",stdin);
#define fo freopen("code.out","w",stdout);

vector <bool> v(1e9+1,false);

int main(){
	boost;
	fi;fo;
	long long x;
	while (scanf("%lld",&x) == 1){
		v[x] = true;
	}
	for (int i = 0 ; i <= 1e9 ; i ++){
		if (!v[i]) {
			cout << i;
			return 0;
		}
	}

	return 0;
}