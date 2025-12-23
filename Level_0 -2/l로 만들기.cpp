#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 'l'보다 작은 문자(a~k)를 모두 'l'로 변환
string ReplaceBelowL(string my_string) {

    // 범위 기반 for문 + 참조(&ch)로 원본 직접 수정
    for (auto& ch : my_string) {
        if (ch < 'l')    // a~k (아스키 97~107 < 108 'l')
            ch = 'l';    // 모두 'l'로 변경
    }
    return my_string;
}
int main() {
    string my_string = "abcdevwxyz";

    auto result = ReplaceBelowL(my_string);

    cout << result << endl;

}