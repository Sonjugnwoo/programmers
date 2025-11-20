#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// A와 B를 서로 바꾼 후, pat 문자열이 존재하는지 확인하는 함수
int ChangeSearchString(string str_arr, string pat) {

    // 람다 함수: 각 문자 c를 검사하여 A→B, B→A로 변환
    transform(str_arr.begin(), str_arr.end(), str_arr.begin(),
        [](char c) { return (c == 'A') ? 'B' : 'A'; });

    // 변환된 문자열에서 pat를 찾기
    return str_arr.find(pat) != string::npos;
}
int main() {

    string str_arr = "ABAB";
    string pat = "ABAB";

    auto result = ChangeSearchString(str_arr,pat);

    cout << result << endl;
}