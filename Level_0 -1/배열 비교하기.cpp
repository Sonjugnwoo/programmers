#include <iostream>
#include <string>
#include <numeric>  // accumulate() 함수를 사용하기 위해 필요
#include <vector>

using namespace std;

// 두 개의 정수 벡터를 비교하는 함수
int CompareArr(vector<int> arr_1,vector<int> arr_2) {
    int len_1 = arr_1.size(); // 첫 번째 벡터의 길이
    int len_2 = arr_2.size(); // 두 번째 벡터의 길이

    // 1단계: 길이 비교
    if (len_1 != len_2)
        return (len_1 > len_2) ? 1 : -1;

    // 2단계: 길이가 같을 때, 합을 비교
    int sum_1 = accumulate(arr_1.begin(), arr_1.end(), 0); // 첫 배열의 원소 합
    int sum_2 = accumulate(arr_2.begin(), arr_2.end(), 0); // 두 번째 배열의 원소 합

    // 합이 같으면 두 벡터는 같다고 판단
    if (sum_1 == sum_2)
        return 0;

    // 합이 다르면, 더 큰 합을 가진 벡터가 더 "크다"라고 판단
    return (sum_1 > sum_2) ? 1 : -1;

}
int main() {

    vector<int> arr_1 = {1,2,3,4,5};
    vector<int> arr_2 = {3,3,3,3,3 };
    auto result = CompareArr(arr_1,arr_2);

    cout << result << endl;
}