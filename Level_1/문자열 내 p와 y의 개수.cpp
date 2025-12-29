#include <iostream>
#include <string>

using namespace std;

bool hasEqualPandYCount(string str)
{
    int count_p = 0;
    int count_y = 0; 

    // 문자열의 모든 문자를 하나씩 순회
    for (auto ch : str) {
        if (ch == 'p' || ch == 'P')      // 대소문자 무시하고 'p' 카운트
            count_p++;                    // 'p' 개수 증가
        else if (ch == 'y' || ch == 'Y') // 대소문자 무시하고 'y' 카운트
            count_y++;                    // 'y' 개수 증가
    }

    // 'p'와 'y'의 개수가 같으면 true(1), 다르면 false(0) 반환
    return count_p == count_y ? 1 : 0;
}

int main() {
    string str = "pPoooyY";

    auto result = hasEqualPandYCount(str);

    cout << result << endl;
}