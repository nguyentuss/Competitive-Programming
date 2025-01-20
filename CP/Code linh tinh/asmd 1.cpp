#include <iostream>
#include <cmath>
using namespace std;

int  t , x , y ;

int add(int a, int b){
    return a+b;
}
int subtract(int a, int b){
    return a-b;
}
int multiple(int a,int b){
    return a*b;
}
int divide(int a,int b){
    int p = a/b;
    return (int)p;
}
void process(){
    if (t==0) 
        cout<< add(x,y) << "\n";
    else if (t==1) 
        cout << subtract(x,y) << "\n";
    else if (t==2) 
        cout << multiple(x,y) << "\n";
    else if (t==3) 
        cout << divide(x,y) << "\n";
}
int main(){
    int n;  
    cin >> n;
    for (int i=1;i<=n;i++)  {
        cin >> t >> x >> y;
        process();
    }
    return 0;
}