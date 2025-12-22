#include <iostream>
#include <string>

using namespace std;


// 문자열 앞쪽의 0들을 모두 제거하는 함수 
string RemoveLeadingZero(string num_str) {
    int count = 0;  // 앞에서부터 연속된 0의 개수를 세는 변수

    // 문자열을 처음부터 순회하면서 앞쪽 0들을 카운트
    for (auto str : num_str) {
        if (str != '0')  // 0이 아닌 첫 번째 문자를 만나면 루프 종료
            break;
        count++;         // 0이면 카운트 1 증가
    }

    // 앞에서 count만큼 자르고 나머지 문자열 반환
    // substr(count): count 위치부터 끝까지 반환
    return num_str.substr(count);
}

int main() {
    string num_str = "0010";

    auto result = RemoveLeadingZero(num_str);

    cout << result << endl;
}