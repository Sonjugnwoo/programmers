#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int sumOfDigits(int n ) {
    auto str = to_string(n);  // 정수를 문자열로 변환: 123 → "123"
    int sum = 0;              // 자릿수 합계 초기화

    // 문자열의 각 문자를 순회
    for (int i = 0; i < str.size(); i++) {
        sum += str[i] - '0';  // 문자 '1'(49) → 숫자 1(1) 변환
    }
}

int main() {
    int n = 123;

    auto result = sumOfDigits(n);

    cout << result << endl;
}
