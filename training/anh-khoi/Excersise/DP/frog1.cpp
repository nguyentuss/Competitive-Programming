#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
 
using namespace std;
 
#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("frog1.inp","r",stdin);
#define fo freopen("frog1.out","w",stdout);
 
vector <int> arr;
 
int main() {
	boost;
	//fi;fo;
 
	int n , x; cin >> n;
 
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		arr.push_back(x);
	} 
 
	vector <int> F(n+1,INT_MAX);
 
	F[0] = 0;
 
	for (int i = 0 ; i < (int) arr.size() ; i++){
		for (int j = i + 1 ; j < i + 3 ; j ++){
			if (j < n) {
				F[j] = min(F[j],F[i] + abs(arr[i] - arr[j]));
			}
		}
	}
 
	cout << F[n-1];
 
	return 0 ;
}