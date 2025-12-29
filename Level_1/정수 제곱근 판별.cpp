#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long largestNumber(long long n) {

    auto temp = sqrt(n);              // n의 제곱근 계산

  // temp가 정수인지 확인 (완전제곱수 판별)
    if (temp == (int)temp)            // 제곱근이 정수 → 완전제곱수
        return pow((temp + 1), 2);    // 다음 제곱수 반환: (√n + 1)^2
    else
        return -1;                    // 완전제곱수가 아님 → -1 반환
}


int main() {
    long long n = 144;

    auto result = largestNumber(n);

    cout << result << endl;

}