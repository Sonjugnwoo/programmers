#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calculateColaExchangeTotal(int a, int b, int n) {
    int answer = 0;  // 교환받은 콜라 총 개수
    int q, r;        // q: 남는 병, r: 새로 받은 콜라

    // n 병이 교환 기준 이상일 때까지 반복
    while (n >= a) {
        q = n % a;           // 교환 후 남는 병 개수
        r = (n / a) * b;     // 이번 교환으로 받은 새 콜라

        n = r + q;           // 새 콜라 마신 후 빈병 = 새로받은 + 남은병
        answer += r;         // 받은 콜라 누적
    }

    return answer;
}

int main() {
    int a = 3;
    int b = 1;
    int n = 20;

    auto result = calculateColaExchangeTotal(a, b, n);

    cout << result << endl;
}