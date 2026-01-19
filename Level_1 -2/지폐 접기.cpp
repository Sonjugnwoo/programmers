#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int calculateMinimumFolds(vector<int> wallet, vector<int> bill) {
    int foldCount = 0;                    // 총 접기 횟수

     // 지갑의 최대/최소 크기
    int walletMax = *max_element(wallet.begin(), wallet.end());
    int walletMin = *min_element(wallet.begin(), wallet.end());

    // 지폐의 현재 최대/최소 크기
    int billMax = *max_element(bill.begin(), bill.end());
    int billMin = *min_element(bill.begin(), bill.end());

    // 모든 지폐가 지갑 범위에 들어올 때까지 반복
    while (billMin > walletMin || billMax > walletMax) {
        // 더 큰 금액의 지폐를 우선적으로 반으로 접기
        if (billMax > billMin) {
            billMax /= 2;  // 큰 지폐 반으로 접기
            foldCount++;
        }
        else {
            billMin /= 2;  // 작은 지폐 반으로 접기
            foldCount++;
        }

        // 최대/최소 순서 보장 
        if (billMax < billMin)
            swap(billMax, billMin);
    }

    return foldCount;

}

int main() {
    vector<int> wallet = { 30,15 };
    vector<int> bill = { 26,17 };


    auto result = calculateMinimumFolds(wallet, bill);

    cout << result << endl;
}