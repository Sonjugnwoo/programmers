#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> reverseDigits(vector<int> arr) {
    vector<int> result;

    sort(arr.begin(), arr.end(),greater<int>());

    arr.pop_back();

    if (arr.empty())
        arr.push_back(-1);

    return arr;
}

int main() {
    vector<int> arr = { 10 };

    auto result = reverseDigits(arr);

    for (auto p : result)
        cout << p << " ";

    cout << endl;
}