#include <iostream>
#include <string>
#include <conio.h>
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
using namespace std;

int main(){
   fast;
   freopen("wc6.inp","r",stdin);
   freopen("wc6.out","w",stdout);
   ll t ; cin >> t;
   while (t--){
      string s; cin >> s;
      ll n ; cin >> n;
      ll d1 = s.size(); 
      ll cap = n / d1;
      double sum = (double) n / d1;
      if ((cap < 1)) {
         cout << s[n-1];
      }
      else {
            ll tam = n;
            ll dem = 0;
            if (cap == sum) {
               if (cap % 2 != 0)
                  cout << s[d1 - 1] << endl;
               else 
                  cout << s[0] << endl;
            }
            else {
               cap ++;
               while (sum != (cap - 1)){
                  tam --;
                  sum = (double) tam / d1;
                  dem++;
               }
            if (cap % 2 != 0)
               cout << s[dem - 1] << endl;
            else {
               cout << s[(d1 - dem + 1) - 1] << endl;
            }
         }
      }
   }
   return 0;
}