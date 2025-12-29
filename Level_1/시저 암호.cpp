#include <iostream>
#include <cctype>   //islower() ,isupper() 사용 
#include <string>

using namespace std;

string createCaesarCipher(string str, int n) {
   
    // 문자열의 모든 문자를 순회하며 수정 (참조로 전달)
    for (auto& ch : str) {
        if (ch == ' ')  // 공백은 건너뛰기
            continue;

        // 소문자('z' 이하) 처리: a-z 순환 
        if (islower(ch))
            ch = (ch - 'a' + n) % 26 + 'a';
        // 대문자('Z' 이하) 처리: A-Z 순환 
        else
            ch = (ch - 'A' + n) % 26 + 'A';
    }
    return str;
}


int main() {
    string str = "a B z";
    int n = 4;

    auto result = createCaesarCipher(str, n);

    cout << result << endl;
}