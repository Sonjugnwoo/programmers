#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int findMinDivisorExcludingOne(int n) {
    int answer = 0;
    vector<int> divisors;

    // 1부터 n-1까지 순회
    for (int i = 1; i < n; i++) {
        if (n % i == 1) 
            divisors.push_back(i);
    }
    answer = *min_element(divisors.begin(), divisors.end());
    return answer;
}


int main() {
    int n = 10;

    auto result = findMinDivisorExcludingOne(n);

    cout << result << endl;
}