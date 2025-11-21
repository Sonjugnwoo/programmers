#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


// 문자열에서 'a', 'b', 'c'를 구분자로 사용해서 구분자 사이의 연속 문자들을 추출
vector<string> ThreeSeparator(string& str_arr) {
    vector<string> result;  // 최종 결과를 담을 벡터
    string word;            // 구분자가 아닌 문자를 임시로 누적할 문자열

    for (auto ch : str_arr) {           // 문자열을 한 글자씩 순회
        if (ch != 'a' && ch != 'b' && ch != 'c')
            word += ch;                 // 구분자가 아니면 누적
        else if (!word.empty()) {       // 구분자를 만났고, 앞에 단어가 있으면
            result.push_back(word);     // 지금까지 누적한 단어 벡터에 저장
            word.clear();               // 임시 버퍼 비움
        }
    }
    if (!word.empty())                  // 마지막 남아있는 단어 처리
        result.push_back(word);

    if (result.empty())                 // 결과가 비어있으면 "EMPTY" 추가 (예외 케이스)
        result.push_back("EMPTY");

    return result;
}
int main() {

    string str_arr = "baconlettucetomato";

    auto result = ThreeSeparator(str_arr);

    for (auto p : result)
        cout << p << " ";
}