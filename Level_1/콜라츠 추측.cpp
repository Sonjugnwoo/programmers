#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 3x+1(Collatz 추측) 사이클 길이 계산 함수
int collatzCycleLength(int num) { 
    int count = 0;                    // 사이클 횟수 카운터
    long long collatz_num = num;      // 오버플로우 방지 long long

    // 시작값이 1이면 사이클 길이 0
    if (num == 1)
        return 0;

    // 1에 도달할 때까지 반복 (500회 제한)
    while (collatz_num != 1) {
        // Collatz 규칙: 짝수면 /2, 홀수면 3x+1
        collatz_num % 2 == 0 ? collatz_num /= 2 : collatz_num = collatz_num * 3 + 1;
        count++;  // 한 사이클 완료

        // 무한루프 방지
        if (count == 500)
            return -1;
    }

    return count;

}

int main() {
    int num = 626331;

    auto result = collatzCycleLength(num);

    cout << result << endl;
}