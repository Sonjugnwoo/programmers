#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 키패드 누르기 문제 해결 함수
string KeypadPressing(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;   // 왼손 초기 위치: * (10으로 표현)
    int right = 12;  // 오른손 초기 위치: # (12으로 표현)  

    // 1,4,7: 무조건 왼손 / 3,6,9: 무조건 오른손 / 나머지: 거리 비교
    for (int num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer += 'L';
            left = num;
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += 'R';
            right = num;
        }
        // 2열 숫자(2,5,8,0)는 거리 비교 후 결정
        else {
            if (num == 0) num = 11;         // 0을 11로 변환 

            // 맨해튼 거리 계산: |a-b|/3(행이동) + |a-b|%3(열이동)
            int ldist = abs(num - left) / 3 + abs(num - left) % 3;
            int rdist = abs(num - right) / 3 + abs(num - right) % 3;

            // 왼손이 더 가까움
            if (ldist < rdist) {
                answer += 'L';
                left = num;
            }
            // 오른손이 더 가까움
            else if (ldist > rdist) {
                answer += 'R';
                right = num;
            }
            // 거리가 같음: 주손잡이 기준 결정
            else {
                if (hand == "right") {
                    answer += 'R';
                    right = num;  // 오른손 위치 갱신
                }
                else {
                    answer += 'L';
                    left = num;  // 왼손 위치 갱신
                }
            }
        }
      
    }
    return answer;
}

int main() {
    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string hand = "right";

    auto result = KeypadPressing(numbers,hand);

    cout << result << endl;
}

