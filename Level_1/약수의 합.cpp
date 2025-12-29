#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int sumOfDivisors(int n) {
    vector<int> number;  // n의 약수들을 저장할 벡터

  // 1부터 n까지 반복하며 약수 찾기
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)      // i가 n의 약수인 경우
            number.push_back(i);  // 약수 벡터에 추가
    }

    // 벡터의 모든 약수 합계 계산 (초기값 0)
    return accumulate(number.begin(), number.end(), 0);
}

int main() {
  
    int n = 12;

    auto result = sumOfDivisors(n);

    cout << result << endl;
}