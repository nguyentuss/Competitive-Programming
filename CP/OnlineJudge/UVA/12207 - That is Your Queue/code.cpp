#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	//ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("text.inp","r",stdin);
	//freopen("output.out","w",stdout);
	int p , c , dem = 0 ;
	while (scanf("%d %d",&p,&c) == 2 && (p != 0) && (c != 0)){
	dem ++;
	vector <int> a;
	queue <int> q , qtemp;
	string s;
	int x , temp , tempmain = 0 , mini  = min(p,c);
	for (int i = 1 ; i <= mini ; i ++) q.push(i);
	for (int i = 1 ; i <= c ; i++) {
		cin >> s;
		if (s == "N") {
			a.push_back(q.front());
			q.push(q.front());
			q.pop();				
			
		}
		else {
			cin >> x;
			while (!q.empty()){
				temp = q.front();
				//cout << temp << " ";
				if (temp != x) {
					qtemp.push(temp);
					q.pop();
				}
				else {
					tempmain = q.front();
					q.pop();
				}
			}
			q.push(x);
			int d = qtemp.size();
			for (int j = 1 ; j <= d ; j++){
				//cout << qtemp.front() << endl;
				q.push(qtemp.front());
				qtemp.pop();
			}
		}
	}
	cout << "Case " << dem << ":" << endl;
	for (int i = 0 ; i < a.size() ; i ++)
		cout << a[i] << endl;
	}
	return 0;
}