#include <iostream>
#include <string>

using namespace std;

// int를 string으로 변환하는 함수
string TransformStr(int n ) {
    return to_string(n);
}

int main() {
    int n = 123;

    auto result = TransformStr(n);

    cout << result << endl;
}