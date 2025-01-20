#include <bits/stdc++.h>

using namespace std;

map<int , int> m;
map<int , int>::iterator it;
priority_queue<int> pq;
int n , x;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (int i = 0 ; i < n ; i++){
		cin >> x;
		m[x] ++;
	}
	int counted = 0;
	int maximum = INT_MIN;
	for (it = m.begin() ; it != m.end() ; it++) {
		if (m[it->first] > 1) pq.push(it -> first);	
		else counted ++;
		maximum = max(maximum , it -> first);
	}
	int temp = 0;
	while (!pq.empty()){
		if (pq.top() < maximum) {
			temp = pq.size();
			break;
		} 
		else {
			pq.pop();
			counted ++;
		}
	}
	if (temp == 0 && counted == 0) cout << 1 << endl << x;
	else cout << 2*temp + counted << endl;
	for (it = m.begin() ; it != m.end() ; it++) 
		if (m[it->first] >= 1) cout << it->first << " ";
	while (!pq.empty()){
		cout << pq.top() << " " ;
		pq.pop();
	}
	return 0;
}		