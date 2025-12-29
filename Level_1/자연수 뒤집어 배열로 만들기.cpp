#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> reverseDigits(long long n) {
    vector<int> result;            

    auto str = to_string(n);         // 정수를 문자열로 변환: 12345 → "12345"

    // 문자열을 뒤에서부터 순회 (뒤집기)
    for (int i = str.size() - 1; i >= 0; i--)
        result.push_back(str[i] - '0');  // 문자 → 숫자 변환 후 벡터 추가


    return result;
}

int main() {
    long long n = 12345;

    auto result = reverseDigits(n);

    for (auto p : result)
        cout << p << " ";

    cout << endl;
}