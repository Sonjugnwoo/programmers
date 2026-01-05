#include <iostream>
#include <math.h>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

int calculateDartScore(string dart_result) {
    vector<int> scores(3, 0);  // 3개 점수 고정
    int idx = 0, prev = 0;     // idx: 현재 점수 인덱스, prev: 임시 숫자

    for (char ch : dart_result) {
        // 1. 숫자 파싱 (10 이상 처리)
        if (isdigit(ch)) {
            prev = prev * 10 + (ch - '0');
        }
        // 2. 보너스 적용 (S=1, D=2, T=3)
        else if (isalpha(ch)) {
            int power = (ch == 'S') ? 1 : (ch == 'D') ? 2 : 3;
            scores[idx++] = pow(prev, power);
            prev = 0;  // 숫자 리셋
        }
        // 3. 옵션 처리 (*, #)
        else {
            if (ch == '*') {
                scores[idx - 1] *= 2;  // 현재 점수 ×2
                if (idx > 1) scores[idx - 2] *= 2;  // 이전 점수 ×2
            }
            else if (ch == '#') {
                scores[idx - 1] *= -1;  // 현재 점수 -1배
            }
        }
    }

    // 4. 최종 합계 반환
    return scores[0] + scores[1] + scores[2];
}

int main() {
    string dart_result = "1D#2S*3S";

    auto result = calculateDartScore(dart_result);

    cout << result << endl;
}