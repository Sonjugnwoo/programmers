#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 'x' 문자 사이에 있는 다른 문자들의 개수를 세는 함수
vector<int> BetweenX(string str_arr) {
    int count = 0;  // 현재 'x' 이후로 센 문자 개수
    vector<int> result;  // 각 구간의 문자 개수를 저장할 벡터

    // 문자열의 각 문자를 순회
    for (auto p : str_arr) {
        if (p != 'x')  // 'x'가 아닌 문자면
            count++;  // 카운트 증가
        else {  // 'x' 문자를 만나면
            result.push_back(count);  // 현재까지의 카운트를 결과에 추가
            count = 0;  // 카운트 초기화
        }
    }

    // 마지막 'x' 이후의 문자들(또는 'x'가 없는 경우) 처리
    result.push_back(count);
    return result;
}
int main() {

    string str_arr = "oxooxoxxox";

    auto result = BetweenX(str_arr);

    for (auto p : result)
        cout << p << " ";
}