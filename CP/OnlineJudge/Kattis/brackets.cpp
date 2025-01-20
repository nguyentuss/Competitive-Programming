#include <bits/stdc++.h>

using namespace std;

//vector <vector<vector<bool>>> f(5005 , vector <vector<bool>>(5005 , vector<bool> (3)));
bool f[5005][5005][3];
string s;

// f[i][freeopen][status] = 0 hoac 1 : Có thể / không thể biến đổi chuỗi 1 có freeopen ngoặc tự do mà đang
// đứng ở hiện tại là trạng thái status
// status = 0 , chưa đi vào đoạn thay đổi
// status = 1 , đag đi vào đoạn thay đổi
// status = 2 , đã đi qua đoạn thay đổi

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> s;
	s = '0' + s;
	int len = s.size() - 1;
	f[0][0][0] = 1;
	for (int i = 0 ; i < len ; i++) {
		for (int j = 0 ; j < len ; j++) {
			for (int status = 0 ; status <= 2 ; status++) {
				if (f[i][j][status] == 0) continue;
				if (status == 1) {
					if (s[i + 1] == '(') {
						f[i + 1][j + 1][2] = 1;
						if (j > 0)
							f[i + 1][j - 1][1] = 1;
					}
					else {
						if (j > 0) 
							f[i + 1][j - 1][2] = 1;
						f[i + 1][j + 1][1] = 1; 
					}
				}
				if (status == 0) {
					if (s[i + 1] == '('){ 
						if (j > 0) 
							f[i + 1][j - 1][1] = 1;
						f[i + 1][j + 1][0] = 1;
					}
					else {
						if (j > 0) 
							f[i + 1][j - 1][0] = 1;
						f[i + 1][j + 1][1] = 1;
					}
				}
				if (status == 2) {
					if (s[i + 1] == '(') 
						f[i + 1][j + 1][2] = 1;
					else {
						if (j > 0) 
						f[i + 1][j - 1][2] = 1;
					}
				}
			}
		}
	}
	if (f[len][0][0] || f[len][0][1] || f[len][0][2]) 
		cout << "possible";
	else cout << "impossible";

	return 0;
}