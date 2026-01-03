#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 주어진 정수 x가 하샤드 수인지 판별하는 함수
// 하샤드 수: 자신의 각 자릿수의 합으로 나누어 떨어지는 수
bool isHarshadNumber(int x) {
    // 정수 x를 문자열로 변환하여 각 자리 숫자에 접근
    string str = to_string(x);

    // 자릿수 합을 저장할 변수
    int digitSum = 0;

    // 문자열의 각 문자(숫자 문자)를 순회하며 자릿수 합 계산
    for (int i = 0; i < str.size(); i++)
        digitSum += str[i] - '0';  // 문자 '0'을 빼서 실제 정수 값으로 변환

    // x가 자릿수 합으로 나누어 떨어지면 하샤드 수이므로 true, 아니면 false
    return x % digitSum == 0;
}

int main() {
    int x = 12;

    auto result = isHarshadNumber(x);

    cout << result << endl;
}
