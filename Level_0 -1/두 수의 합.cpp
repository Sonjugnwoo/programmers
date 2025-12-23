#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string SumStr(string a,string b) {
    string result = "";

    // 1. 공통 계산 길이 결정 (짧은 문자열 기준)
    int len = min(a.size(), b.size());

    // 2. **LSB부터 계산** 위해 두 입력 뒤집기 (맨 뒤 자리부터)
    reverse(a.begin(), a.end());   // a: MSB→LSB → LSB→MSB
    reverse(b.begin(), b.end());   // b: MSB→LSB → LSB→MSB

    int carry = 0;  // 올림 수

    // 3. **1단계: 공통 길이만큼 자리별 덧셈** (LSB부터)
    for (int i = 0; i < len; i++) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;  // 문자→숫자 + 이전 올림
        result += (sum % 10) + '0';                      // 자리수만 저장 (LSB부터)
        carry = sum / 10;                                // 다음 자리 올림 계산
    }

    // 4. **2단계: 긴 문자열의 남은 앞자리 처리** (carry 전달)
    if (a.size() > b.size()) {                        // a가 더 길면
        for (int i = len; i < a.size(); i++) {         // a의 남은 앞자리들 (원본 MSB들)
            int sum = (a[i] - '0') + carry;
            result += (sum % 10) + '0';
            carry = sum / 10;
        }
    }
    else if (b.size() > a.size()) {                   // b가 더 길면
        for (int i = len; i < b.size(); i++) {        // b의 남은 앞자리들 (원본 MSB들)
            int sum = (b[i] - '0') + carry;
            result += (sum % 10) + '0';
            carry = sum / 10;
        }
    }

    // 5. 최종 올림 처리 (최상위 자리)
    if (carry > 0)
        result += carry + '0';

    // 6. **결과 뒤집기** (LSB→MSB → MSB→LSB 복원)
}

int main() {
    string a = "18446744073709551615";
    string b = "287346502836570928366";

    auto result = SumStr(a,b);

    cout << result << endl;
}