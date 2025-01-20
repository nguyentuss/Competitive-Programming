#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <int> v;

int main (){
	boost;
	int n , x; cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> x;
		v.push_back(x);
	}

	int needtoerase;

	for (int i = 1 ; i<= n; i++) {
		cin >> needtoerase;
		cout << v[needtoerase - 1] << " ";
		v.erase(v.begin() + needtoerase - 1);
	}


	return 0;
}