#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>	
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("book.inp","r",stdin);
#define fo freopen("book.out","w",stdout);

vector <int> v , asort;

int main(){
	boost;
	fi;fo;
	int n , x; cin >> n;
	for (int i = 1 ; i <= n; i++){
		cin >> x;
		v.push_back(x);
	}
	int c = n;
	for (int i = n ; i >= 1 ; i --) {
		if (v[i - 1] == c) c --;
	}
	cout << c;

	return 0;
}