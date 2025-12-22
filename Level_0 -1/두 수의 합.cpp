#include <iostream>
#include <string>

using namespace std;

string SumStr(string a,string b) {
    string result = "";
  
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int len = (a.size() > b.size() ? b.size() : a.size());
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result += (sum % 10) + '0';
        carry = sum / 10;
    }

    if(carry > 0){
        result += carry + '0';
    }
         
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a = "18446744073709551615";
    string b = "287346502836570928366";

    auto result = SumStr(a,b);

    cout << result << endl;
}