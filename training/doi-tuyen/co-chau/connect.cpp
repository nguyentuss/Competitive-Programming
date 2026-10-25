#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("connect.inp","r",stdin);
#define fo freopen("connect.out","w",stdout);

vector <string> v;

int main(){
	boost;
	fi;fo;
	int n; cin >> n;
	string s;
	for (int i = 0 ; i < n ; i++){
		cin >> s;
		v.push_back(s);
	} 
	for (int i = 0 ; i < n ; i++) 
		for (int j = 0 ; j < n ; j++) 
			if (v[i] + v[j] > v[j] + v[i]) swap(v[i],v[j]);

	for (int i = 0 ; i < n ; i++) cout << v[i];
	return 0;
}