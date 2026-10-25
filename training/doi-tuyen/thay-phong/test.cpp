#include <bits/stdc++.h>

using namespace std;

int m , n , k;

int main() {
    cin >> m >> n >> k;
    int maxi = min(m/2 , n);    
    // maxi là số cặp lớn nhất mà có thể ghép đx 
    k = k - (m - maxi*2);
    k = k - (n - maxi);
    // 2 cái dòng này là trừ phần dư 
    if (k <= 0) {
        cout << maxi;
        // nếu mà mình trừ phần dư mà <= 0 nghĩa là 
        //mình không cần lấy ông bà nào trong số cặp để đi nhiệm vụ
        // thì số cặp lớn nhất không cần đụng
    }
    else {
        if (k % 3 != 0) 
         k = k + 3 - (k % 3);
        // cái khúc này mình sẽ biến thành 1 số chia hết cho 3
        // ví dụ k = 5 thì k = 5 + 3 - (5 % 3)
        //              <=> k = 5 + 3 - 2
        //              <=> k = 6 
        maxi = max(0 , maxi - (k/3));
        // vì mỗi cặp gồm 3 ng nên sẽ lấy k/3 
        // vì nó có TH sẽ trừ ra số âm nên mình lấy max(0 , maxi - (k/3)) để tránh số âm
        cout << maxi;
    }

    return 0;
}