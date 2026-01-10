#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string findLargestNumberFromCommonChars(string x, string y) {
    string answer = "";
    unordered_multiset<char> temp(y.begin(), y.end());

    // x에서 y에 있는 문자들만 추출
    for (auto ch : x) {
        auto pos = temp.find(ch);            // ch 찾기
        if (pos != temp.end()) {             // y에 존재하면
            answer += ch;                              // answer에 추가
            temp.erase(pos);                 // y에서 1개 소모
        }
    }

    // 내림차순 정렬 (가장 큰 수)
    sort(answer.begin(), answer.end(), greater<>());

    // 특수 케이스 처리
    if (answer.empty())                                // 공통 문자 없음
        answer.append("-1");
    else if (answer.find_last_not_of('0') == string::npos) {  // 모든 문자 '0'
        answer.clear();
        answer.append("0");                            // "000" → "0"
    }
    return answer;
}

int main() {
    string x = "5525";
    string y = "1255";


    auto result = findLargestNumberFromCommonChars(x,y);

    cout << result << endl;
}