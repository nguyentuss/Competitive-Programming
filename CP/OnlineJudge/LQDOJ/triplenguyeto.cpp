#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);


struct tuhandsome{
	int x , y;
};

vector <int> v;
vector <tuhandsome> ans;
int main(){
	boost;
	int n; cin >> n;
	vector <bool> Eratosthenes(n + 2);

	Eratosthenes[0] = true;
	Eratosthenes[1] = true;
	for (int i = 2 ; i * i <= n ; i++) {
		if (!Eratosthenes[i])
			for (int j = i * i ; j <= n ; j += i)  
				Eratosthenes[j] = true;
	}
	
	int count = 0;
	for (int i = 2 ; i <= n ; i++) 
		if (!Eratosthenes[i])
			v.push_back(i);
		cout << v.size();
	//for (int i = 0 ; i < (int) v.size() ; i++) cout << v[i] << " " ;
	//	cout << endl;
	/*for (int i = 0 ; i < (int) v.size() - 1 ; i++) {
		for (int j = i + 1 ; j < (int) v.size() ; j ++){
			//cout << v[i] << " " << v[j] << endl;
			if (v[i] + v[j] <= n && Eratosthenes[v[i] + v[j]] == false) {
				ans.push_back((tuhandsome) {v[i],v[j]});
				count ++;
			}
			else if (v[j] + v[i] > n && Eratosthenes[v[i] + v[j]] == true) break;
		}
	} */

	cout << count << endl;
	for (int i = 0 ; i < (int) ans.size() ; i++) 
		cout << ans[i].x << " " << ans[i].y << endl;


	return 0;
}