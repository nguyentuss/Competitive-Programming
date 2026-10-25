#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);

	freopen("taphop.inp","r",stdin);
	freopen("taphop.out","w",stdout);

	int n , m , x; cin >> m >> n ;
	set <int> s;
	set <int>::iterator it;
	vector <int> v1 , v2 , a , h;
	vector <bool> count1(1e4+1,false) , count2(1e4+1,false);
	bool check = true;

	for (int i = 0 ; i < m ; i++) {
		cin >> x;
		v1.push_back(x);
	}
	for (int i = 0 ; i < n ; i ++) {
		cin >> x;
		v2.push_back(x);
	}

	for (int i = 0 ; i < m; i ++)
		s.insert(v1[i]);
	
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		s.insert(v2[i]);
	}
	if (n > 0 && m > 0) {
		for (it = s.begin() ; it != s.end() ; it ++) 
			cout << *it << " ";
		cout << endl;
	}

	for (int i = 0 ; i < m ; i++) {
		count1[v1[i]] = true;
	}
	for (int i = 0 ; i < n ; i++) {
		count2[v2[i]] = true;
	}

	for (int i = 1 ; i <= 1000 ; i++) {
		if (count1[i] && count2[i]){
			a.push_back(i);
			check = false;
		}
	}
	if (check) cout << '#' << endl;
	else
	{
		//sort(a.begin(),a.end());
		for (int i = 1 ; i <= 1000 ; i++) {
			if (count1[i] && count2[i])
				cout << i << " ";
		}
		cout << endl;
	}
	check = true;
	for (int i = 1 ; i <= 1000 ; i ++) {
		if (count1[i] && !count2[i]) {
			h.push_back(i);
			check = false;
		}
	}
	//cout << count1[5] << " " << count2[5] << endl;
	if (check) cout << '#' << endl;
	else
	for (int i = 1 ; i <= 1000; i++) {
		if (count1[i] && !count2[i])
		cout << i << " ";
	}

	return 0;
}