#include <iostream>
#include <string>

using namespace std;

// 문자열→정수 변환 함수 
int stringToInteger(string str) {
    int result = stoi(str); // 문자열을 정수로 변환
   
    return result;
}

int main() {
    string str = "-1234";
    auto result = stringToInteger(str);

    cout << result << endl;
}