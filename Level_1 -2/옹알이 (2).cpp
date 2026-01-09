#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int countValidBabyPronunciations(vector<string> babbling) {
    int answer = 0;
    vector<string> baby = { "aya", "ye", "woo", "ma" };
    for (string crying : babbling) {  // 각 옹알이 순회
        int idx = 0;                  // 현재 위치 포인터
        string prev = "";             // 이전 발음 (연속 체크용)

        // 문자열 끝까지 연속 매칭 시도
        while (idx < crying.size()) {
            bool matched = false;     // 이번 위치 매치 성공 플래그

            // 모든 기준 발음으로 시도
            for (string ba : baby) {
                size_t len = ba.size();
                // 1. 길이 충분한지, 2. 정확히 매치, 3. 이전과 다른 발음
                if (idx + len <= crying.size() &&
                    crying.substr(idx, len) == ba && ba != prev) {
                    idx += len;       // 매치 성공 → 다음 위치로
                    prev = ba;        // 이전 발음 갱신
                    matched = true;   // 매치 성공 표시
                    break;            // 다음 발음 위치로 이동
                }
            }
            if (!matched) break;  // 매치 실패 → 조기 종료
        }

        // 완전히 소진(idx == size())된 경우만 유효
        if (idx == crying.size()) answer++;
    }
    return answer;
}

int main() {
    vector<string> babbling = { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"};

    auto result = countValidBabyPronunciations(babbling);

    cout << result << endl;
}