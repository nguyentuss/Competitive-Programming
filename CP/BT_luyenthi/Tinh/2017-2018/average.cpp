#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("average.inp","r",stdin);
	freopen("average.out","w",stdout);
	int n; cin >> n;
	long a[n];long long s = 0;
	for (int i = 0 ; i < n ; i++){
		cin >> a[i];
		s += a[i];
	}
	//cout << s;
	sort(a,a+n);
	//for (int i = 0 ; i < n ; i++) cout << a[i] << " ";
	double aver;
	aver = (double) a[0];
	for (int i = 1 ; i < n ; i++)
		aver = (double) (aver + a[i]) / 2;
	cout <<  fixed << setprecision(5) << (aver * n) - s;
	return 0;
}