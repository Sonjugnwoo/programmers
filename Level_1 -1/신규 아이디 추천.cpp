#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 신규 ID 추천 규칙에 따라 ID를 정규화하는 함수(7단계 처리)
string recommendNewId(string new_id) {
    // 1단계: 모든 대문자를 소문자로 변환
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    // 2단계: 허용 문자(소문자, 숫자, -, _, .) 외 모두 제거
    new_id.erase(remove_if(new_id.begin(), new_id.end(),
        [&](char c) {
        if (c == '-' || c == '_' || c == '.') return false;
        return !(isdigit(c) || isalpha(c));
    }), new_id.end());

    // 3단계: 연속된 점("..")을 하나의 점으로 치환
    auto pos = new_id.find("..");
    while (pos != string::npos) {
        new_id.erase(pos, 1);  // 첫 번째 점만 제거하여 ".." → "."
        pos = new_id.find("..");
    }

    // 4단계: 앞/뒤 점 제거 (독립 if문으로 앞뒤 모두 체크)
    if (!new_id.empty() && new_id.front() == '.')
        new_id.erase(new_id.begin());

    if (!new_id.empty() && new_id.back() == '.')
        new_id.erase(new_id.end() - 1);

    // 5단계: 빈 문자열이면 'a' 추가
    if (new_id.empty())
        new_id.push_back('a');

    // 6단계: 16자 이상이면 앞 15자만 남기고, 끝이 점이면 제거
    if (new_id.length() >= 16) {
        new_id.erase(15);  // 인덱스 15부터 삭제 (앞 15자만 남김)
        if (!new_id.empty() && new_id.back() == '.')
            new_id.erase(new_id.end() - 1);
    }

    // 7단계: 길이가 3 미만이면 마지막 문자를 반복 추가
    while (new_id.length() < 3)
        new_id.push_back(new_id.back());

    return new_id;
}

int main() {
    string new_id = "...!@BaT#*..y.abcdefghijklm";

    auto result = recommendNewId(new_id);

    cout << result << endl;
}
