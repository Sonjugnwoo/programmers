#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Contains(string my_string , string target) {
    // my_string에서 target 찾기
    // find() 성공: 위치 인덱스 반환
    // find() 실패: string::npos 반환
    return my_string.find(target) != string::npos ? 1 : 0;
}
int main() {

    string my_string = "banana";
    string target = "123";

    auto result = Contains(my_string, target);

    cout << result << endl;
}