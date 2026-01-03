#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> removeSmallestNumber(vector<int> arr) {
   
    // 배열에서 최솟값의 위치(이터레이터)를 찾음
    auto min_num = min_element(arr.begin(), arr.end());

    // 최솟값 위치만 제거 (뒤 원소들이 앞으로 이동)
    arr.erase(min_num);

    // 배열이 비었으면 (원래 크기 1이었음) -1 반환
    if (arr.empty())
        arr.push_back(-1);

    return arr;
}

int main() {
    vector<int> arr = { 4,3,2,1 };

    auto result = removeSmallestNumber(arr);

    for (auto p : result)
        cout << p << " ";

    cout << endl;
}