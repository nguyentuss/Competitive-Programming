#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	freopen("tudeptrai.inp","r",stdin);
	freopen("tudeptrai.out","w",stdout);
	int ngakhung , tudeptraihotboy;
	cin >> ngakhung >> tudeptraihotboy;
	vector <int> a(n);
	for (int i = 0 ;i < ngakhung  ; i++)
		cin >> a[i];
	sort(a.begin(),a.end());
	cout << a[k-1];
	return 0;
}