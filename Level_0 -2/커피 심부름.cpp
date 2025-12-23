#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 주문 총액 계산: americano/anything=4500, cafelatte=5000
int CalculateOrderTotal(vector<string> order) {
    int result = 0; 

    for (auto str : order) {
        if (str.find("cafelatte") != string::npos) {
            result += 5000;   // 라떼 우선 체크 
        }
        else {
            result += 4500;  // americano/anything/기타 모두 아메리카노
        }
    }
    return result;
}

int main() {
    vector<string> order = { "americanoice", "americano", "iceamericano" };

    auto result = CalculateOrderTotal(order);

    cout << result << endl;

}