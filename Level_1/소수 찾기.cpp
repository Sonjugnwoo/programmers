#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countPrimesUpTo(int n) {
    int count = 0;      // 소수 개수 카운트
    bool flag = false;   // i가 소수인지 플래그

    for (int i = 2; i <= n; i++) {        // 2부터 n까지 검사
        flag = true;                      // i를 소수로 가정
        for (int j = 2; j * j <= i; j++) {  // 2부터 √i까지 나누어 봄
            if (i % j == 0) {             // 나누어 떨어지면
                flag = false;             // i는 소수 아님
                break;                    // 더 볼 필요 없음
            }
        }
        if (flag)                         // 내부 루프 끝까지 flag=true면
            count++;                     // 소수 1개 증가
    }

    return count;
}

int main() {
    int n = 10; // 2 3 5 7 

    auto result = countPrimesUpTo(n);

    cout << result << endl;
}