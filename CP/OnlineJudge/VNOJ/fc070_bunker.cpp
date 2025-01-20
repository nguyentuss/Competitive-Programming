#include <bits/stdc++.h>

using namespace std;

#define ii pair<double , double>
#define x first
#define y second
#define lech (double) (1e-4)
#define esp (double (1e-9))
#define PI (double) (3.14159265)

int n;
double R;
vector<ii> v;
double ans;
double degrees;

double distance(ii a , ii b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int checked(double x) {
	ii pos1 = ii(R*cos(x) , R*sin(x));
	ii pos2 = ii(R*cos(x + lech) , R*sin(x + lech));
	ii pos3 = ii(R*cos(x - lech) , R*sin(x - lech));
	double sum1 = 0 , sum2 = 0 , sum3 = 0;
	for (int i = 0 ; i < n ;i++) {
		double dist1 = distance(v[i] , pos1);
		double dist2 = distance(v[i] , pos2);
		double dist3 = distance(v[i] , pos3);
		double goc1 = acos(1 - (dist1*dist1)/(2*R*R));
		double goc2 = acos(1 - (dist2*dist2)/(2*R*R));
		double goc3 = acos(1 - (dist3*dist3)/(2*R*R));
		sum1 += R*goc1 , sum2 += R*goc2 , sum3 += R*goc3;
	}
	if (sum1 < (sum2 + esp) && (sum1 + esp) >= sum3) return 1;
	else 
		if ((sum1 + esp) >= sum2 && sum1 < (sum3 + esp)) return 2;
	else
		if (sum1 <= (sum2) && sum1 <= (sum3)) {
			degrees = x;
			ans = sum1;
		}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> n;
	for (int i = 1 ; i <= n ; i++) {
		double x; cin >> x;
		v.push_back(ii(R*cos(x) , R*sin(x)));
	}
	double l = 0.0 , r = 360.0 - esp;
	for (int i = 0 ; i < 20 ; i++) {
		double mid = (l + r)/2.0;
		double change = checked(mid);
		if (change == 1) {
			l = mid;
			cout << "YES";
		}
		else if (change == 2) r = mid;
	}
	cout << fixed << setprecision(3) << degrees << '\n';
	cout << fixed << setprecision(3) << ans;
	return 0;
}