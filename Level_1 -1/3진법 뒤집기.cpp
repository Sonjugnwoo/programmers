#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 10진수를 3진법으로 변환 → 뒤집기 → 다시 10진수로 변환하는 함수
int convertTernaryReverseAndConvertBack(int n) {
    vector<int> ternaryDigits;  // 3진법 각 자릿수를 저장할 벡터

    // 1단계: 10진수를 3진법으로 변환 (낮은 자리부터 저장)
    while (n != 0) {
        ternaryDigits.push_back(n % 3);  // 나머지 = 3진법 자리값
        n /= 3;                          // 다음 자리로 이동
    }

    // 2단계: 3진법 숫자를 뒤집기 (높은 자리부터 낮은 자리로)
    reverse(ternaryDigits.begin(), ternaryDigits.end());

    // 3단계: 뒤집힌 3진법을 다시 10진수로 변환
    int result = 0;
    for (size_t i = 0; i < ternaryDigits.size(); i++)
        result += ternaryDigits[i] * pow(3, i);  // 자리값 × 3^위치
    return result;
}

int main() {
    int n = 125;

    auto result = convertTernaryReverseAndConvertBack(n);

    cout << result << endl;
}