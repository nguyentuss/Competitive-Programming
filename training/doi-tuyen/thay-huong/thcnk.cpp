
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define sz(x)  (long long)(x).size()
#define sqr(x) (x)*(x)
#define sof sizeof
#define resz resize
#define ins insert
#define Vec vector
#define lowerB lower_bound
#define upperB upper_bound
#define mkp make_pair
#define mkt make_tuple
#define act(a,v) (get<(long long)a>(v))
#define mod 1000000007
#define mod1 998244353
#define N 200003  //N idhar hai
#define M 9901  //M idhar hai
#define inf 1e18
#define minf -1e18
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define ms(dp,a) memset(dp,(ll)a,sof(dp))
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define fr(i,b) for(int (i)=(0);(i) < (b); ++(i))
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PRECISION(n) std::cout.unsetf ( std::ios::floatfield );std::cout.precision((ll)n)
#define getsm(v) accumulate(all(v),(ll)0)
#define getmx(v) max_element(all(v))
#define getmn(v) min_element(all(v))
#define ws1(a) cout<<(a)<<" "
#define wr1(a) cout<<(a)<<endl
#define wr2(a,b) cout<<(a)<<" "<<(b)<<endl
#define wr3(a,b,c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl
#define wr4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define ww1(a) cout<<(a)<<"\n"
#define ww2(a,b) cout<<(a)<<" "<<(b)<<"\n"
#define ww3(a,b,c) cout<<(a)<<" "<<(b)<<" "<<(c)<<"\n"
#define ww4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<"\n"
#define FileIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define fill(dp,a,b) for(int i=0;i<a;i++)for(int j=0;j<b;j++)dp[i][j]=-1;
#define PI 3.14159265358979323846264338327950288419716939937510
#define fi first
#define se second
#define here cout<<"RSSB"<<endl
#define dbg cout<<"Krishna"<<endl
#define showzero cout<<std::showpoint
#define bitcount( x ) (ll)__builtin_popcountll( x )
#define ls(i) (1ll<<(i))
using namespace __gnu_pbds; //required
using namespace  std ;
typedef double db;
typedef long long ll ; //long long
typedef vector<int>vi ;
//typedef vector<l>vl ;
typedef vector<ll>vll ;
typedef vector<vector<ll> >vvl ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ;
typedef vector<pll>vpll;
typedef vector<string>vstr;
typedef vector<bool>vbool ;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T = ll>
void readArray(Vec<T> &v, ll n){T a ;for(ll i=0 ; i<n ; i=i+1){cin>>a ;v.pb(a);}}
template <class T = ll>
void printArray(Vec<T> &v , ll a = 0){for(ll i=a ; i<v.size() ; i=i+1){/*v[i] = max((ll)0,v[i]);*/cout<<v[i]<<" " ;}cout<<"\n" ;}
double logy(ll n , ll b){if(b==0){return(-1);}if(n==1){return(0);}return((db)log10(n)/(db)log10(b));}
long long power(long long k , long long n , long long m=mod){long long res = 1;while(n){if(n%2!=0){res = (res*k)%m ;}k = (k*k)%m ;n = n/2 ;}return(res) ;}
double powerD(double k , long long n ){double res = 1;while(n){if(n%2!=0){res = (res*k) ;}k = (k*k) ;n = n/2 ;}return(res) ;}
ll gcdExtend(ll a , ll b , ll &x , ll &y){if(a==0){x = 0;y = 1;return(b);}ll x1,y1;ll g = gcdExtend(b%a,a,x1,y1);x = y1 - (b/a)*x1;y = x1;return(g);}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
#define lcm(a,b) ((a/gcd(a,b))*b)
void mul(ll &x , ll a){if(a<0){a+=mod;}else{a%=mod;}x = (x%mod*a%mod)%mod;}
double distance(pair<double,double> a , pair<double,double> b){return((double)(sqrt( sqr(a.fi-b.fi) + sqr(a.se-b.se))));}

long long  C[1001][1001],n,k,i,j;

int main() 
{
	freopen("thcnk.inp","r",stdin);
	freopen("thcnk.out","w",stdout);
	
	cin >> n >> k;
	
	for (i=0;i<=n;i++) 
	{
		C[i][0]=1;
		C[i][i]=1;
	}

	for (i=2;i<=n;i++) 
		for (j=1;j<i;j++) 
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			
	cout << C[n][k];
	return 0;
}