#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

// 벡터에서 **연속된 중복 원소**를 제거
vector<int> removeConsecutiveDuplicates(vector<int> arr){
   
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}

int main() {
    vector<int> arr = {4,4,4,3,3 };

    auto result = removeConsecutiveDuplicates(arr);

    for(auto p : result)
        cout << p << " ";

    cout << endl;
}