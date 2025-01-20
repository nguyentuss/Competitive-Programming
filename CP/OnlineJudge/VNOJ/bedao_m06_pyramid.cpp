#include <bits/stdc++.h>

using namespace std;

#define esp (double) (1e-7)

double x , y;

bool calc(double a) {
	double b = y - a;
	double c = x + a;
	if (a + esp > 0.0 && b + esp > 0.0 && c + esp> 0.0) {
		if (a + esp > b) swap(a , b); 
		cout << fixed << setprecision(9) << a << " " << b << " " << c;
		return true;
	}
	return false;
}

void PT(double a, double b, double c,double &x1, double &x2){
    double delta = b*b - 4*a*c;
    if(delta < 0 + esp){
        x1=x2=0.0;
    }
    else if(delta == 0.0){
        x1 = x2 = -b/(2*a);
    }
    else{
        delta = sqrt(delta);
        x1 = (-b + delta)/(2*a);
        x2 = (-b - delta)/(2*a);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> x >> y;
	double a1 , b1 , c1 , x1 , x2;
	a1 = 1 , b1 = -(2*y + 2*x) , c1 = y*y - x*x;
	PT(a1 , b1 , c1 , x1 , x2);
	if (calc(x1)) return 0;
	calc(x2);
	return 0;
}