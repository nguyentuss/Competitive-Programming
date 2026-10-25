#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("frog2.inp","r",stdin);
#define fo freopen("frog2.out","w",stdout);

vector <int> arr;

int main() {
	boost;
	fi;fo;

	int n , x , k ; cin >> n >> k ;

	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		arr.push_back(x);
	} 

	vector <int> F(n+1,INT_MAX);

	F[0] = 0;

	for (int i = 0 ; i < (int) arr.size() ; i++){
		for (int j = i + 1 ; j < i + k + 1 ; j ++){
			if (j < n) {
				F[j] = min(F[j],F[i] + abs(arr[i] - arr[j]));
			}
		}
		//F[i+k] = min(F[i+k],F[i] + abs(arr[i] - arr[i+k]));
	}

	//for (int i = 0 ; i < n ; i ++) cout << F[i] << " " ;
	//cout << endl;
	cout << F[n-1];

	return 0 ;
}