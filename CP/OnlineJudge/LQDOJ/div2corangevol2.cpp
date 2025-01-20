	#include <iostream>
	#include <cmath>
	#include <algorithm>

	using namespace std;
	#pragma GCC optimize("Ofast")

	int N; 

	int main(){
		cin >> N;
		for (int i = 0 ; i < N ; i++) {
			float a , b , c , d , e , f;
			cin >> a >> b >> c >> d >> e >> f;
			float y1 = e * b - f*a;
			float y2 = b * c - d*a;
			float x , y;
			if (y1 == y2) y = 0;
			else y = (e*b - f*a)/(b * c - d*a);
			x = (e - c * y)/a;
			cout << x << " " << y ;
			if (((y == (int) y) && y > 0) && ((x == (int) x) && x > 0)) cout << x << " " << y << endl;
			else cout << "?" << endl;
		}
		return 0;
}