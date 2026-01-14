#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> getMinKeyPresses(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    vector<int> min_press(26, 101);        // A~Z 최소 누름 횟수 배열 (101=키 없음 플래그)

  // 1단계: 각 알파벳의 모든 keymap 중 최소 누름 횟수 계산
    for (const auto& p : keymap) {         // 각 자판 행 순회
        for (int j = 0; j < p.size(); j++) {  // 각 행의 문자 위치 순회
            int idx = p[j] - 'A';            // 문자 → 배열 인덱스 변환 (A=0, B=1, ...)
            min_press[idx] = min(min_press[idx], j + 1);  // 최소값 갱신
        }
    }

    // 2단계: 각 targets 문자열 처리
    for (const string& ch : targets) {     // 각 목표 문자열 순회
        int sum = 0;                       // 누름 횟수 합계
        bool ok = true;                    // 입력 가능 여부 플래그

        for (char ta : ch) {               // 문자열 내 각 문자 순회
            int idx = ta - 'A';            // 문자 → 배열 인덱스 변환
            if (min_press[idx] == 101) {   // 해당 키가 keymap에 없음
                ok = false;                // 입력 불가능 표시
                break;                     // 루프 종료
            }
            sum += min_press[idx];         // 누름 횟수 누적
        }
        answer.push_back(ok ? sum : -1);   // 가능:true→sum, 불가능:-1
    }
    return answer;
    return answer;
}


int main() {
    vector<string> keymap = { "AA"};
    vector<string> targets = { "B" };

    auto result = getMinKeyPresses(keymap, targets);

    for (auto p : result)
        cout << p << " ";

    cout << endl;
}