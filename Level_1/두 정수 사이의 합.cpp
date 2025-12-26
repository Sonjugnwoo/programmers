#include <iostream>
#include <string>
#include <vector>

using namespace std;
//두 정수 a, b가 주어졌을 때 두 수 사이에 존재하는 모든 정수의 합을 반환
long long sumBetweenTwoNumbers(int a, int b) {
    long long sum = 0;   // 결과 합을 저장할 변수 (오버플로 방지용 long long)

    // a, b 중 더 큰 값과 작은 값을 구함
    int max_num = max(a, b);
    int min_num = min(a, b);

    // 작은 수부터 큰 수까지 모든 정수를 더함
    for (int i = min_num; i <= max_num; i++)
        sum += i;

    return sum;
}

int main() {
    int a = 3;
    int b = 5;

    auto result = sumBetweenTwoNumbers(a,b);

    cout << result << endl;
}
