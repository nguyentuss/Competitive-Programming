#include <iostream>
#include <vector>
#include <functional>

using namespace std;
struct segment{
	vector <int> a;
};

vector <segment> v;

int main(){

	v.push_back((segment){});
	v[0].push_back((segment) {2});

	return 0;
}