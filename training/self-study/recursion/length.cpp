#include <iostream>
using namespace std;
#define maxn 255

string x[maxn] , s;
int n;

void write(){
	bool kt = true;
	for (int l = 1 ; l <= n - 1 ; l++){
		if (x[l] == "B"){
			if (x[l+1] == "B"){
				kt = false;
				break;
			}
		}
	}
	if (kt) {
		for (int l = 1 ;l <= n ; l ++)
			cout << x[l];
		cout << "\n";
	}
}

void backt(int i){
	for (int j = 0 ; j <= 1 ; j++){
		if (j == 0) {s = "A";}
		else {s = "B";} 
		x[i] = s;
		if (i == n) write();
		else backt(i+1);
	}
}

int main(){
	cin >> n;
	backt(1);
	return 0;
}