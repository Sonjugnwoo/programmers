#include <iostream>
#include <string>

using namespace std;


// 문자열의 각 숫자 문자를 실제 숫자로 변환하여 합계 반환
int SumStr(string num_str) {
    int sum = 0;

    // 문자열의 각 문자를 순회하면서 숫자로 변환 후 합산
    for (auto ch : num_str)
        sum += ch - '0';  // (ASCII '0'=48 빼기)
   
    return sum;
}

int main() {
    string num_str = "123456789";

    auto result = SumStr(num_str);

    cout << result << endl;
}