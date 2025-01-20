#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct segment {
	int	freeopen , freeclose , maxCorrect;
};

string s;
vector <segment> IT(4*(1e6 + 7));

segment query(int index , int L , int R , int left , int right) {
	if (left <= L && right >= R) {
		return IT[index];
	}
	if (left > R || L > right) {
		return (segment) {0 , 0 , 0};
	}
	int mid = (L + R)/2;
	segment temp;
	segment vleft = query(2*index , L , mid  , left , right);
	segment vright = query(2*index + 1 , mid + 1 , R , left , right);
	temp.maxCorrect = vleft.maxCorrect + vright.maxCorrect + min(vleft.freeopen , vright.freeclose);
	temp.freeopen = vleft.freeopen - min(vleft.freeopen , vright.freeclose) + vright.freeopen;
	temp.freeclose = vright.freeclose - min(vleft.freeopen , vright.freeclose) + vleft.freeclose;
	return temp;
}

void calc(int index , int left , int right) {
	if (left == right) {
		if (s[left - 1] == '(') {
			IT[index].freeopen = 1;
			IT[index].freeclose = 0;
			IT[index].maxCorrect = 0;
		}
		else {
			IT[index].freeclose = 1;
			IT[index].freeopen = 0;
			IT[index].maxCorrect = 0;
		}
		return;
	}
	else {
		int mid = (left + right) / 2;
		calc(index * 2 , left , mid);
		calc(index * 2 + 1 , mid + 1 , right);
		IT[index].maxCorrect = IT[2 * index].maxCorrect + IT[2 * index + 1].maxCorrect + min(IT[2*index].freeopen , IT[2*index + 1].freeclose);
		IT[index].freeopen = IT[2 * index].freeopen - min(IT[2 * index].freeopen , IT[2 * index + 1].freeclose) + IT[2 * index + 1].freeopen;
		IT[index].freeclose = IT[2 * index + 1].freeclose - min(IT[2 * index].freeopen , IT[2 * index + 1].freeclose) + IT[2 * index].freeclose;	
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> s;
	int n = s.size();
	calc(1 , 1 , n);
	int q , l , r;
	cin >> q;
	for (int i = 0 ; i < q ; i++) {
		cin >> l >> r;
		cout << 2*query(1 , 1 , n , l , r).maxCorrect << endl;
	}
	return 0;
}