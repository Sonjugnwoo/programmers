#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
//배열에서 divisor로 나누어 떨어지는 정수만 남겨 오름차순 정렬 후 반환하는 함수
vector<int> getDivisibleNumbers(vector<int> arr, int divisor) {

    //remove_if + erase 조합으로 조건에 맞지 않는 원소 제거
    arr.erase(remove_if(arr.begin(), arr.end(),
        [&](int x) {return x % divisor != 0 ? 1 : 0; }), arr.end());

            
    sort(arr.begin(), arr.end());

    //만약 divisor로 나누어지는 수가 하나도 없으면 [-1] 반환
    if (arr.empty())
        arr.push_back(-1);

    return arr;
}

int main() {
    vector<int> arr = { 2,36,1,3 };
    int divisor = 5;

    auto result = getDivisibleNumbers(arr,divisor);

    for (auto p : result)
        cout << p << " ";

    cout << endl;
}