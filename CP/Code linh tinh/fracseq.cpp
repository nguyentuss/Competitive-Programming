#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long double dbl;

const int N=2e6+10;
const int inf = 1e17;

int np, prime[N];
bool isp[N];
int X[50];
int m[N];
int minn = inf;
vector<int> factors; 
void sieve(int N) {
    memset(isp, true, sizeof isp);
    isp[0] = isp[1] = false;
    for(int i=2; i<N; i++) if(isp[i]) {
        prime[++np]=i;
        for(int j=2*i; j<N; j+=i) {
            isp[j]=false;
        }
    }
}

int mul(int a, int b, int m) {
    a%=m; if(a<0) a+=m;
    b%=m; if(b<0) b+=m;
    int q = ((dbl)a * (dbl)b) / (dbl)m;
    int r = a*b - q*m;
    return (r<0 ? r+m:r);
}
int pwr(int a, int n, int m) {
    int ans(1);
    while(n) {
        if(n & 1) ans = mul(ans, a, m);
        if(n >>= 1) a = mul(a, a, m);
    }
    return ans%m;
}
int myrand(int n) {
    return rand()%n*rand()%n*rand()%n;
}
bool ispmiller(int p) { 
    if(p<2) return false;
    if(p==2) return true;
    if(p%2==0) return false;
    int s=p-1; s>>=__builtin_ctzll(s);
    for(int i=0; i<60; i++) {
        int val=pwr(myrand(p-1)+1,s,p), temp=s;
        while(temp!=p-1 && 1<val && val<p-1) {
            val=mul(val,val,p);
            temp<<=1;
        }
        if(val!=p-1 && temp%2==0) return false;
    }
    return true;
}
int pollardrho(int n) {
    if(n==1) return 1;
    if(n%2==0) return 2;
    int c=myrand(n-1)+1, x=myrand(n-2)+2, y=x;
    int d=1; while(d==1) {
        x=mul(x,x,n)+c; if(x>=n) x-=n;
        y=mul(y,y,n)+c; if(y>=n) y-=n;
        y=mul(y,y,n)+c; if(y>=n) y-=n;
        d=__gcd(abs(x-y),n);
        if(d==n) return (ispmiller(n) ? n:pollardrho(n));
    }
    return d;
}


map<int ,int> m;

void backtr(int i , int ans) {
	if (i == factors.size()) return;
	for (int j = 0 ; j <= m[i] ; j ++) {
		if (j == 0) backtr(i + 1 , ans);
		else {
			ans *= factors[i];
			minn = min(minn , ans);
			backtr(i + 1 , ans);
		} 		
	}
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
	freopen("test.inp","r",stdin);
	sieve(1e6);
    int t; cin >> t;
    while (t--) {
	    int n; cin >> n;
	    n = n*n*n;
	    while (1) {
	    	n++;
	    	m.clear();
	    	factors.clear();
	    	if (ispmiller(n)) {
	    		cout << n - 1 << '\n';
	    		break;
	    	}
	    int tmpn = n;
	    for(int i=1; i<np && prime[i]*prime[i]<=n; i++) {
	        if(n%prime[i]==0) { 
	            while(n%prime[i]==0) {
	                n /= prime[i];
	                m[factors.size()]++;
	            }
	            factors.push_back(prime[i]);
	        }
	    }
	    if(ispmiller(n)) {
	        m[factors.size()]++;
	        factors.push_back(n);
	    }
	    else if(n>1) { 
	        int x = pollardrho(n);
	        assert(x > 1e6);
	        m[factors.size()]++;
	        m[factors.size() + 1]++;
	        factors.push_back(x);
	        factors.push_back(n/x);
	    }
	    backtr(0 , 1);
	    n = tmp - minn;
		}	
	}
    return 0;
}