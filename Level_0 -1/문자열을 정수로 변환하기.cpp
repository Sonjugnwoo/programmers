#include <iostream>
#include <string>

using namespace std;


// 문자열을 정수로 변환하는 함수
int TransformStr(string num_str) {
    // std::stoi(): string을 int로 변환 (C++11 표준 함수)
    return stoi(num_str);
}

int main() {
    string num_str = "8542";

    auto result = TransformStr(num_str);

    cout << result << endl;
}