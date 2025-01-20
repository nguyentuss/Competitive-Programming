#include <iostream>
using namespace std;
int diem;
int main(){
	cin >> diem;
	if (diem >=8) {
		cout << "Loai Gioi";
	}
	else if (diem >=7) {
		cout << "Loai Kha";
	}
	else if (diem >=5) {
		cout << "Loai Trung Binh";
	}
	else if (diem >=4) {
		cout << "Loai Yeu";
	}
	else 
		cout << "Loai Kem	";
	return 0;
	
}