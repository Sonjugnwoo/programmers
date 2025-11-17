#include <iostream>
#include <string>
#include <numeric>
#include <vector>

using namespace std;

int DistanceOperator(vector<int> num_list) {
    // 리스트 크기가 11 이상이면 합계 반환
    if (num_list.size() >= 11)
        return accumulate(num_list.begin(), num_list.end(), 0);
    else
    // 리스트 크기가 10 이하이면 곱셈 반환
        return accumulate(num_list.begin(), num_list.end(), 1, [](int a, int b)
    {return a * b; });
}

int main() {
    vector<int> num_list = { 3, 4, 5, 2, 5, 4, 6, 7, 3, 7, 2, 2, 1 };

    auto result = DistanceOperator(num_list);

    cout << result << endl;
}