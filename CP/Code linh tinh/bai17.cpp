#include <iostream>

using namespace std;

int main(){

	double a , b , k;
	int dem;
	cin >> a >> b >> k;

	dem = 0;
	while (a<=b){
		a += (a*(k/100));
		dem++;
	}

	cout << dem << "\n";
	return 0;
}