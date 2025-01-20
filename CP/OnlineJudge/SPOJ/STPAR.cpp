#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	//ios::sync_with_stdio(0); cin.tie(NULL);
	int n;
	while (scanf("%d",&n) == 1 && (n != 0)){
	stack <int> s;
	vector <int> a;
	int m;
	for (int i = 0 ; i < n ; i++){
		cin >> m;
		a.push_back(m);
	}
		
	int truck = 1;bool check = true;
	for (int i = 0; i < a.size() ; i++)
	{
		while ((i!=0) && (!check) && (s.size() != 0) && (s.top() == truck)){
			//cout << s.top() << endl;
			truck ++; 
			s.pop();
			if (s.empty()) break;
		}
		
		if (a[i] == truck) truck ++;
		else{
			s.push(a[i]);
			check = false;
		}
	}
	//cout << truck;
	int d = s.size();
	for (int i = 0 ; i < d ; i++){
		//cout << s.top() << " ";
		if (s.top() == truck && s.size() != 0) truck ++;
		s.pop();
	}
	if (truck == n + 1) cout << "yes" << endl;
	else cout << "no" << endl;
	}
	return 0;
}