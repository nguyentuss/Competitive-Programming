#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <limits.h>

using namespace std;

#define inf (int) (1e9 + 7)

int n , k , c , x;
typedef pair<int , int> ii;
vector <ii> v;
vector <ii> choose;
vector <int> a , b;
vector <int> m(51);
map <int , int> counted;
map <int , int>::iterator it;

void init() {
	v.clear();
	a.clear();
	b.clear();
	counted.clear();
	choose.clear();
	for (int i = 0 ; i <= 50 ; i++) m[i] = inf;
}
void read() {
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < n ;i++) {
		cin >> x;
		b.push_back(x);
	}
	for (int i = 0 ; i < n; i++) {
		choose.push_back(ii(b[i] , a[i]));
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("sc4.inp","r",stdin);
	freopen("sc4.out","w",stdout);
	int t; cin >> t;
	for (int test = 0 ; test < t ; test ++) {
		cin >> n >> k >> c;
		init();
		read();
		for (int i = 0 ; i < n ; i++) {
			m[a[i]] = min(m[a[i]] , b[i]);
			counted[a[i]] ++;
		}
		for (it = counted.begin() ; it != counted.end() ; it++) 
			v.push_back(ii(m[it -> first] , it -> first));
		sort(v.begin() , v.end());
		bool check = false;
		int total = 0;
		//for (int i = 0 ; i < (int) v.size() ; i++) cout << v[i].first << " " << v[i].second << endl;
		int go = 0;
		for (int i = 0 ; i < (int) v.size(); i ++) {
			total += v[i].first;
			go ++;
			if (total > c) {
				check = true;
				if (i == k ) cout << "NOT FRIENDSHIP BUT NOT LOVE" << endl;
				else if (i < k) cout << "FRIENDSHIP" << endl;
				else if (i > k) cout << "LOVE" << endl;
				break;
			} 
		}
		if (!check) {
			if (go == k) {
				bool check1 = false;
				sort(choose.begin() , choose.end());
				for (int i = 0 ; i < (int) choose.size() ; i++) {
					if (m[choose[i].second] != choose[i].first  && choose[i].first + total <= c) {
						check1 = true;
						cout << "LOVE" << endl;
						break;	
					}
				}
				if (!check1) cout << "NOT FRIENDSHIP BUT NOT LOVE" << endl;
			}
			else if (go < k) cout << "FRIENDSHIP" << endl;
			else if (go > k) cout << "LOVE" << endl;
		}
	}
	return 0;
}