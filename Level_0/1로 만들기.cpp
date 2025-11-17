#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Create1(vector<int> num_list) {
    int count = 0;
    // num_list의 각 숫자를 순회
    for (auto p : num_list) {  // p: 값 복사

        // 현재 숫자 p를 1로 만들 때까지 반복
        while (p != 1) {
            if (p % 2 == 0)  // 짝수인 경우
                p /= 2;  
            else  // 홀수인 경우
                p = (p - 1) / 2; 

            count++;  // 연산 횟수 증가
        }
    }
    return count;
}

int main() {
    vector<int> num_list = { 12,4,15,1,14 };

    auto result = Create1(num_list);

    cout << result << endl;
}