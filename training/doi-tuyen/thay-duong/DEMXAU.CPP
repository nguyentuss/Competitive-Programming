#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("DEMXAU.inp","r",stdin);
#define fo freopen("DEMXAU.out","w",stdout);

string k,s,S[200000];

long l,d,a=0;

bool kt=true;

int main(){
	boost;
	fi;fo;
	cin>>s;
	for(int i = 0; i < (int)s.length() ; i++)
	 for(int j = i ; j< (int)s.length() ; j++){
	    k="";
	  	for(int z=i;z<=j;z++) 
	  		k+=s[z];

	  	for(int l=1;l<=d;l++) 
	  		if(k==S[l]) 
	  			kt=false;
	  	if(kt) {
	  		d+=1; 
	  		S[d]=k;
	  	}
	  	kt=true;
	 }
	cout<<d;
	return 0;
	}