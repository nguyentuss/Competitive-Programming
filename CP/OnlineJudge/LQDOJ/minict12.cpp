#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define maxelements (long) 1000007
#define fi freopen("minict12.inp","r",stdin);
#define fo freopen("minict12.out","w",stdout);

int main (){
	boost;
	//fi;fo;
	vector<long> v;
	long n,k,x; cin >> n >> k;

	for (long i = 0 ; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	vector <long> count(maxelements,0);

	long countelements = 0 , l = 0 , leftmax = 0 , rightmax = 0 , length = 0 , ans = LLONG_MIN;

	for (long  i = 0 ; i < n ; i++) {
		count[v[i]] ++;
		if (count[v[i]] == 1) countelements ++;
			while (countelements > k) {
				count[v[l]] --;
				if (count[v[l]] == 0) countelements --;
				l ++;
			}
			if (i - l > ans) {
				ans = i - l;
				leftmax = l;
				rightmax = i;
			}
	}	

	cout << leftmax+1 << " " << rightmax + 1;

	return 0;
}	