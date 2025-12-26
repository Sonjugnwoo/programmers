#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;
// 문자열 벡터를 n번째 문자 기준으로 오름차순 정렬
vector<string> solution(vector<string> strings, int n) {

    // sort: 사용자 정의 비교자(lambda)를 이용한 정렬
    sort(strings.begin(), strings.end(),

        // 람다 함수: 비교 기준 정의
        // 반환값: true이면 a가 b보다 앞에 옴
        [n](const string& a, const string& b) {

        // 1 . n번째 문자가 같을 때
        if (a[n] == b[n])
            return a < b;   // 문자열 전체 비교 (ex. "abc" < "abd")

        // 2.  n번째 문자가 다를 때
        return a[n] < b[n]; }); 

    return strings;
}

int main() {
    vector<string> strings = { "edc","abc" };

    int n = 2;

    auto result = solution(strings, n);

    for (auto p : result)
        cout << p << " ";

    cout << endl;

}