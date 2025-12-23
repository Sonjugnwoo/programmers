#include <iostream>
#include <string>
#include <vector>

using namespace std;

// a, b의 홀짝 조합에 따른 연산 결과 반환
int ComputeByParity(int a, int b) {
    // 1. **둘 다 홀수**: 제곱의 합
    if (a % 2 == 1 && b % 2 == 1)
        return (a * a) + (b * b);

    // 2. **둘 다 짝수**: 절댓값 차이
    else if (a % 2 == 0 && b % 2 == 0)
        return abs(a - b);

    // 3. **홀짝 다름**: 2배의 합
    else
        return 2 * (a + b);
}

int main() {
    int a = 3;
    int b = 5;

    auto result = ComputeByParity(a, b);

    cout << result << endl;
}