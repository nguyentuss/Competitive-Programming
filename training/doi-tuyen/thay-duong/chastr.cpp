#include<bits/stdc++.h>
using namespace std;
string s,x;
char so1='1',so2='0';
long t=0;
bool KT(string s){
	if(s[0]==so1 && s.length()==1) return false;
	return true; 
}
int main(){
	freopen("CHASTR.INP","r",stdin);
	freopen("CHASTR.OUT","w",stdout);
	cin>>s;
	for(long i=0; i<s.length(); i++) x+='0';
	if(!KT(s)) cout<<-1;
	else{
			if(s[s.length()-1]==so1 && s[s.length()-2]==so1){
				s[s.length()-1]='0';
				s[s.length()-2]='0';
				t+=1;
		}
			for(long i=1; i<s.length(); i++){
				if(s[i]==so1 && s[i-1]==so1){
					s[i]='0';
					s[i-1]='0';
					t+=1;
		}
	}
			for(long i=1; i<s.length()-1; i++){
				if(s[i]==so1 && s[i-1]=='0' && s[i+1]=='0') {
					t+=1; s[i]='0';
				}
			}
			if(x==s)	cout<<t;
			else cout<<-1;
		}

	return 0;
}