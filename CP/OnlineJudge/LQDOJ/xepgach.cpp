#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

#define MIN (int) (-1e9 + 7)

int n;
struct segment{
	int a , b , h;
};

bool cmp(segment &temp1 , segment &temp2) {
	return temp1.a < temp2.a; 
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("xepgach.inp","r",stdin);
	//freopen("xepgach.out","w",stdout);

	cin >> n;

	vector <segment> v;
	int x , y , z;
	for (int i = 1 ; i <= n; i++) {
		cin >> x >> y >> z;
		v.push_back((segment) {x,y,z});
	}

	sort(v.begin() , v.end(), cmp);

	vector <int> dptallest(n + 1);
	vector <int> dpmost(n + 1);

	dpmost[0] = 0;
	dptallest[0] = 0;
	for (int i = 1 ; i <= n ; i++){
		dptallest[i] = v[i-1].h;
		dpmost[i] = 1;
		for (int j = i - 1 ; j >= 0 ; j --) {
			if (j > 0){
				if (v[i - 1].a > v[j - 1].a && v[i - 1].b > v[j - 1].b) {
					dptallest[i] = max(dptallest[i] , dptallest[j] + v[i-1].h);
					dpmost[i] = max(dpmost[i] , dpmost[j] + 1);
				}
			}
		}
	}

	int thetallest = MIN , themost = MIN;
	for (int i = 1 ; i <= n ; i++) {
		thetallest = max(thetallest , dptallest[i]);
		themost = max(themost , dpmost[i]);	
	}
	cout << themost << " " << thetallest;

	return 0;
}