#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countBalancedStringSplits(string str) {
        int answer = 0;                    // 분리된 구간 개수
        bool flag = false;                 // 마지막 구간 처리용 플래그
        char first_ch = str[0];            // 현재 구간의 첫 번째 문자
        int x = 1, y = 0;                  // x: first_ch 개수, y: 다른 문자 개수 (첫 글자는 이미 x=1)

        // i=1부터 시작 (첫 글자는 이미 카운트됨)
        for (int i = 1; i < str.length(); i++) {
            if (first_ch != str[i])        // 기준문자가 아니면
                y++;                       // 다른 문자 카운트 증가
            else
                x++;                       // 기준문자 카운트 증가

            // x와 y가 같아지면 → 한 구간 완료!
            if (x == y) {
                flag = true;
                answer++;                  // 구간 하나 추가
                first_ch = str[i + 1];     // 다음 구간의 첫 글자 설정
                x = 1, y = 0;              // 카운트 초기화 (새 첫글자 1개로 시작)
                i++;                       // 다음 구간 시작위치로 스킵
                continue;
            }
            flag = false;                  // 구간 미완료 상태
        }

        // 루프 종료 후 처리: 마지막 구간이 남았거나 불완전 종료
        if (!flag || first_ch == str.back())
            answer++;

    return answer;
}

int main() {

    string str = "abracadabra";

    auto result = countBalancedStringSplits(str);

    cout << result << endl;
}