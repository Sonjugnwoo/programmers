#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 문자열 벡터에서 "같은 길이를 가진 문자열의 최대 개수"를 구하는 함수
int BindStr(vector<string> strArr) {
    // 인덱스: (문자열 길이 - 1), 값: 해당 길이를 가진 문자열의 개수
    // 길이를 1 ~ 31까지 허용한다고 가정하고 31칸짜리 벡터를 0으로 초기화
    vector<int> len(31, 0);

    // 각 문자열의 길이에 따라 카운트 증가
    for (const auto& str : strArr)
        len[str.size() - 1]++;

    // 가장 많이 등장한 길이의 문자열 개수를 저장할 변수
    int max_count = 0;

    // len 벡터를 순회하면서 최대값 찾기
    for (int i : len)
        if (i > max_count)
            max_count = i;

    // 가장 많이 등장한 문자열 길이의 개수 반환
    return max_count;
}

int main() {
    vector<string> strArr = { "a","bc","d","efg","hi" };

    auto result = BindStr(strArr);

    cout << result << endl;
}