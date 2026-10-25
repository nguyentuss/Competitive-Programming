#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n,m,x,y;
char s[100][100];

int main(){
   	ios_base::sync_with_stdio(0); cin.tie(NULL);
   	cout.tie(NULL);
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> s[i][j];
        }
    }
    cin >> x >> y;
    ll cnt = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = m+1 ;j <= 2*m;j++){
            s[i][j] = s[i][j - cnt];
            cnt += 2;
        }
        cnt = 1;
    }
    cnt=1;
    for(int i = n+1 ; i <= 2*n ; i++){
        for(int j = m+1 ; j <= 2*m;j++){
            s[i][j]=s[i-cnt][j];
        }
        cnt+=2;
    }
    cnt=1;
    for(int i=n+1;i<=2*n;i++){
        for(int j=1;j<=m;j++){
            s[i][j]=s[i-cnt][j];
        }
        cnt+=2;
    }
    if(s[x][y]=='.')s[x][y]='#';
    else s[x][y]='.';

    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*m;j++){
            cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}