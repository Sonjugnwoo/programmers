#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


// 'x'를 구분자로 문자열을 분리하고 공백을 제거한 후 정렬하는 함수
vector<string> CutString(string str_arr) {
    vector<string> result;  // 분리된 문자열을 저장할 벡터
    string word;  // 현재 구간의 문자열을 임시 저장

    // 문자열의 각 문자를 순회
    for (auto ch : str_arr) {
        if (ch != 'x')  // 'x'가 아닌 문자면
            word += ch;  // word에 추가
        else {  // 'x'를 만나면
            result.push_back(word);  // 현재 word를 결과에 추가
            word.clear();  // word 초기화
        }
    }
    if (!word.empty())  // 마지막 남은 문자열이 있으면
        result.push_back(word);  // 결과에 추가

    for (auto& s : result)  // 각 문자열을 참조로 받음
        s.erase(remove(s.begin(), s.end(), ' '), s.end());  // 공백 제거

    // 빈 문자열 제거 (공백만 있던 문자열 처리)
    result.erase(remove(result.begin(), result.end(), ""), result.end());

    sort(result.begin(), result.end());  // 사전순 정렬
    return result;
}
int main() {

    string str_arr = "axxbxx";


    auto result = CutString(str_arr);

    for (auto p : result)
        cout << p << " ";
}