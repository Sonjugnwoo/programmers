#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string alternateCaseBySpace(string str) {
    int idx =0;

    // 문자열 전체 순회
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {  // 공백인 경우
            idx = 0;          // 인덱스 리셋 (새 단어 시작)
            continue;         // 공백은 그대로 유지
        }

        // 공백 제외 인덱스 기준 홀짝 처리
        if (idx % 2 == 0)     // 짝수 인덱스: 대문자
            str[i] = toupper(str[i]);
        else                  // 홀수 인덱스: 소문자
            str[i] = tolower(str[i]);

        idx++;                // 다음 문자로 인덱스 증가
    }

    return str;
}

int main() {
    string str = "try hello world";

    auto result = alternateCaseBySpace(str);

    cout << result << endl;
}