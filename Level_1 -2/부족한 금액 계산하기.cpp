#include <iostream>

using namespace std;

long long calculateMissingMoney(int price, int money, int count) {
    // 총 필요 금액 = price * (count * (count + 1) / 2)
   long long temp = (long long)(count * (count + 1) / 2) * price - money;

   // 부족 금액이 양수면 반환, 아니면 0
    return temp >= 0 ? temp : 0;
}

int main() {
    int price = 3;
    int money = 20;
    int count = 4;

    auto result = calculateMissingMoney(price, money, count);

    cout << result << endl;
}