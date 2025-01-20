#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);


int main(){
	boost;

	int l ,  r; cin >> l >> r;
	vector <bool> sieve(r - l + 1);


	for (int i = 2 ; i * i <= r ; i ++)
		for (int j =  max(i * i, (l + i - 1) / i * i) ; j <= r ; j += i) 
			sieve[j - l] = true;

	if (1 >= l) { 
    	sieve[1 - l] = true;
	}
	for (int i = l ; i <= r ; i ++) 
		if (!sieve[i - l]) cout << i << endl;


	return 0;
}