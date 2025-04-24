#include <bits/stdc++.h>
using namespace std;
int main (){
    long long a, b;
    while (cin >> a){
        if (a==0){
            break;
        }
        cin >> b;
        vector <vector <double>> dist (a+1, vector <double>(a+1,0));
        for (long long i = 0; i < b; i++){
            long long c, d, e;
            cin >> c>> d>> e;
            dist[c][d]= max (dist[c][d], e*1.0/100.0);
            dist[d][c]= max (dist[d][c], e*1.0/100.0);
        }
        for (long long k=1; k <=a; k++){
            for (long long i =1; i <=a; i++){
                for (long long j =1; j <=a; j++){
                    dist[i][j]= max (dist[i][j], dist[i][k]* dist[k][j]);
                }
            }
        }
        cout <<  fixed << setprecision(6)<<dist[1][a]*100<< " percent"<<endl;
    }
}