#include <iostream>
#include <string>

using namespace std;

// 아이디 유효성 검사 함수 
bool isValidIdFormat(string str) {

    // 아이디 길이가 4 또는 6글자가 아닌 경우 유효하지 않음
    if (str.size() == 4 || str.size() == 6) {
        // 모든 문자가 숫자(0-9)만 허용 ('0'~'9' 범위)
        for (auto ch : str) {
            //  if (!isdigit(s[i])) 도 가능 
            if (ch < '0' || ch > '9')  // 숫자가 아닌 문자('A', 소문자 등) 발견 시
                return false;
        }
    }
    else
        return false; // 길이가 4,6글자가 아니면 유효하지 않음

    return true; // 모든 조건 통과 시 유효함
}

int main() {
    string str = "a234";

    auto result = isValidIdFormat(str);

    cout << result << endl;
}