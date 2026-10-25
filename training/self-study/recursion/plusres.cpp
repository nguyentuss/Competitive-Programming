#include <iostream>

using namespace std;

int n , s;

void input(){
	cin >> n;
}

int sum(int n){
	if (n == 1) return 1;
	return n + sum(n-1);
}

int main(){
	input();
	cout << sum(n);
}