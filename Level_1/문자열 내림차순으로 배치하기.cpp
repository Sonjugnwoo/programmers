#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

// 문자열 내림차순 정렬 함수 
string sortStringDescending(string str) {
    // str.begin()부터 str.end()까지 greater<int>() 비교자로 내림차순 정렬
    sort(str.begin(), str.end(), greater<int>());

    return str; // 정렬된 문자열 반환
}

int main() {
    string str = "Zbcdefg";

    auto result = sortStringDescending(str);

    cout << result << endl;
}