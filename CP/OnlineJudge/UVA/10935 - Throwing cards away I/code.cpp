#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector> 

using namespace std;

queue<int> q;
vector <int> v;
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("inp.inp","r",stdin);
	//freopen("out.out","w",stdout);
	int n; 
	while (cin >> n && n != 0) {
		while (!q.empty()) q.pop();
		v.clear();
		for (int i = 1 ; i <= n ; i++) 
			q.push(i);
		int go = 0;
		while ((int) q.size() != 1 && !q.empty()) {
			int trungngu = q.front();
			q.pop();
			go ++;
			if (go % 2 == 0) q.push(trungngu);
			else v.push_back(trungngu);
		}
		if (v.empty()) cout << "Discarded cards:";
		else 
		cout << "Discarded cards: ";
		for (int i = 0 ; i < (int) v.size() ; i++) {
			if (i != (int) v.size() - 1)
				cout << v[i] << ", ";
			else cout << v[i] ;
		}
		cout << endl;
		cout << "Remaining card: " << q.front() << endl;
	}
	return 0;
}