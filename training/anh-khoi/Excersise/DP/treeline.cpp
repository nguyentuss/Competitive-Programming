#include <bits/stdc++.h>

using namespace std;


#define ll long long
#define M (ll) (1e9)

int n , h;
vector <int> v;
set<int> s;
vector <bool> sieve(200007 , false);

long long POW(long long a , long long x) {
	if (x == 0) return 1%M;
	long long child = POW(a , x / 2)%M;
	long long ans = (child%M*child%M)%M;
	if (x % 2 != 0) ans = (ans%M*a%M)%M;
	return ans%M;
}

void Eratosthenes() {
	for (int i = 2 ; i * i <= 2*(n+1) ; i++) {
		if (!sieve[i]) {
			for (int j = i * i ; j <= 2*(n+1) ; j += i) 
				sieve[j] = true;
		}
	}
	return;
}

vector <int> calc(int N) {
	vector <int> X(200007 ,  0);
	int temp;
	for (int i = 2 ; i <= N ; i++) {
		if (!sieve[i]) {
			temp = N;
			while (temp >= i) {
				temp /= i;
				X[i] += temp;	
			}
		}
	}

	return X;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> n >> h;
	int x;
	for (int i = 1 ; i <= n ;i++) {
		cin >> x;
		v.push_back(x);
	}
	int ans = 1 , minpos;
	vector <int> temp;
	temp = v;
	reverse(temp.begin() , temp.end());
	for (int i = 0 ; i < n ; i++) {
		s.insert(temp[i]);
		if (s.find(temp[i]) != s.begin())  {
			cout << i + 1 << '\n';
			break;
		}
	}
	Eratosthenes();
	vector <int> p1(200007) , p2(200007) , p3(200007);
	p1 = calc(2*(n+1)) , p2 = calc(n + 2) , p3 = calc(n + 1);
	for (int i = 2 ; i <= 2*(n+1); i++) {
		if (!sieve[i]) {
			ans = (ans%M*POW(i , p1[i] - p2[i] - p3[i])%M)%M;
		}
	}
	cout << ans%M;
	return 0;
}