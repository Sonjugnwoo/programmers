#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 문자열로 표현된 간단한 산술 연산(+, -, *)을 계산하는 함수
int OperatorString(string str_arr) {
    // 연산자(+, -, *) 위치 찾기
    // find_first_of는 주어진 문자들 중 가장 먼저 나타나는 것의 인덱스를 반환
    auto pos = str_arr.find_first_of("+-*");

    // 연산자를 찾지 못한 경우 (string::npos는 -1을 의미)
    if (pos == string::npos)
        return -1;  // 오류를 나타내기 위해 -1 반환

    // 연산자 문자 저장
    char op = str_arr[pos];

    // 왼쪽 피연산자 추출: 문자열 시작(0)부터 연산자 위치(pos) 이전까지
    // substr(시작위치, 길이)를 사용하여 부분 문자열 추출
    // stoi()는 문자열을 정수로 변환 (string to integer)
    int left = stoi(str_arr.substr(0, pos));

    // 오른쪽 피연산자 추출: 연산자 다음(pos+1)부터 문자열 끝까지
    // substr에서 두 번째 인자를 생략하면 끝까지 추출
    int right = stoi(str_arr.substr(pos + 1));

    // 연산자에 따라 적절한 연산 수행
    switch (op) {
    case '+':
        return left + right;  // 덧셈
    case '-':
        return left - right;  // 뺄셈
    case '*':
        return left * right;  // 곱셈
    default:
        return -1;  // 예상치 못한 연산자의 경우 예외 처리
    }
}
int main() {

    string str_arr = "43 + 12";

    auto result = OperatorString(str_arr);

    cout << result << endl;
}