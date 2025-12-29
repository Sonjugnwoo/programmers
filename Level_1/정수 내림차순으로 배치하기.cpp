#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long largestNumber(long long n) {
   
    auto str = to_string(n);

    // 문자들을 내림차순 정렬 (큰 숫자부터 앞으로)
    sort(str.begin(), str.end(), greater<int>());

    auto result = stoll(str);          // 정렬된 문자열을 long long으로 변환

    return result;
}


int main() {
    long long n = 118372;

    auto result = largestNumber(n);

    cout << result << endl;

}