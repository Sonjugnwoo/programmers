#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 전화번호 보안을 위해 앞자리 4개 제외하고 *로 마스킹하는 함수
string maskPhoneNumber(const string& phone_number) {
    // phone_number를 복사해서 원본 보존
    string masked = phone_number;

    // 마지막 4자리를 제외한 앞부분만 *로 치환
    transform(masked.begin(), masked.end() - 4, masked.begin(),
        [](char c) { return '*'; });

    return masked;
}


int main() {
    string phone_number = "01033334444";
    
    auto result = maskPhoneNumber(phone_number);

    cout << result << endl;
}