#include <iostream>

using namespace std;

int n;

void star(int n){
	if (n == 0) return;
	star(n-1);
	for (int i = 1 ; i <= n ; i++)
		cout << "*";
	cout << "\n";

}

int main(){
	cin >> n;
	star(n);
	return 0;
}