#include <iostream>
#include <string>
#include <vector>

using namespace std;

int convertNumberWordString(string str) {
    string temp;
    string number;
    vector<pair<char, string>> numbers =  // 최종 숫자 문자열 (문자열 누적)
    { {'0',"zero"},{'1',"one"},{'2',"two"},{'3',"three"},
      {'4',"four"},{'5',"five"},{'6',"six"},{'7',"seven"},
      {'8',"eight"},{'9',"nine"}
    };

    // 문자열을 문자 단위로 순회
    for (auto ch : str) {
        if (isdigit(ch)) {     // 숫자 문자인 경우
            number += ch;
        }
        else {               // 영문자인 경우
            temp += ch;
        }

        // temp에 충분한 길이의 단어가 쌓이면 매칭 시도 (최소 3글자)
        if (temp.size() >= 3) {
            for (auto& che : numbers) {
                // 영단어가 temp에 포함되어 있는지 확인
                if (temp.find(che.second) != string::npos) {
                    number += che.first;  // 숫자 문자 추가
                    temp.clear();         // 버퍼 초기화
                    break;
                }
            }
        }
    }

    // 숫자 문자열을 정수로 변환하여 반환
    int answer = stoi(number);
    return answer;
}


int main() {
    string str = "one4two";

    auto result = convertNumberWordString(str);

    cout << result << endl;

}