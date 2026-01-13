#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int countZeroSumTriplets(vector<int> number) {
    int answer = 0;
    int len = number.size();
   
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int sum = number[i] + number[j];
            for (int k = j + 1; k < len; k++) {
                if (sum == -number[k])
                    answer++;
            }
        }
    }


    return answer;
}

int main() {

    vector<int> number = { -3, -2, -1, 0, 1, 2, 3 };

    auto result = countZeroSumTriplets(number);

    cout << result << endl;
}