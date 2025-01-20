#include <bits/stdc++.h>

using namespace std;
int n , x[101] = {0};

bool check(int s){
	for (int i = 2 ; i <= sqrt(s);i++)
		if (s % i == 0) return false;
	if (s > 1) return true;
}

int ghinghiem(){
	bool kt = true;
	for (int i = 1;i<= 2*(n-1);i++){
		if (!check(x[i]+x[i+1])) {
							kt = false;
							break;}
	}
	if (kt == true){
		for (int i = 1 ; i <= 2*n ; i++)
			cout << x[i] << " ";
		cout << "\n";
	}
}

int ktra(int i){
	x[1] = 1;
	for (int j = 2 ; j <= 2*n; j ++){
		x[i] = j;
		if (i == n) ghinghiem();
		ktra(i+1);
	}
}


int main(){

	cin >> n;
	ktra(1);
	return 0;
}