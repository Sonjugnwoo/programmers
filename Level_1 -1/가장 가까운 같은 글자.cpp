#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 문자열의 각 문자에 대해, 자신보다 앞쪽에서 같은 문자가 등장
vector<int> getCharDistance(string str) {
    vector<int> answer;
    int dist = -1;

    // 문자열의 각 문자에 대해 반복
    for (int i = 0; i < str.size(); i++) {
        dist = -1;              // 기본값: 이전 등장 없음
        char ch = str[i];       // 현재 문자

        // 현재 문자 이전 구간을 순회
        for (int j = 0; j < i; j++) {
            if (ch == str[j]) { // 같은 문자가 이전에 나왔다면 거리 갱신
                dist = i - j;
            }
        }

        // 계산된 거리 저장
        answer.push_back(dist);
    }
    return answer;
}

int main() {
    string str = "foobar";

    auto result = getCharDistance(str);

    for (auto p : result)
        cout << p << " ";

    cout << endl;
}