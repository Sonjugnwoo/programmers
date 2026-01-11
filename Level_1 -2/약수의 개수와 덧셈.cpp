#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sumByDivisorCount(int left, int right) {
    int answer = 0;

    // left부터 right까지 모든 수를 순회
    for (int i = left; i <= right; i++) {
        int count = 0;  // 약수 개수 카운터

        // 약수 개수 계산
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {           // j가 약수인 경우
                count++;                // 작은 약수 j 카운트
                if (j * j != i)         // 큰 약수 i/j 추가 (자신이면 제외)
                    count++;
            }
        }
            
        // 약수 개수 판별 후 연산
        if (count % 2 == 0)         // 짝수 개 → 더하기
            answer += i;
        else                        // 홀수 개(완전제곱수) → 빼기
            answer -= i;
    }

    return answer;
}

int main() {
    int left = 13;
    int right = 17;

    auto result = sumByDivisorCount(left,right);

    cout << result << endl;

}