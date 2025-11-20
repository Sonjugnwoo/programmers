#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


vector<string> ThreeSeparator(string& str_arr) {
   vector<string> result;
   string word;
   auto pos = str_arr.find_first_of("abc");
   for (int i = 0; i < str_arr.size(); i++) {
       if (i == pos)
           str_arr.erase(pos);
       else
           word += str_arr[i];
       pos = str_arr.find_first_of("abc");
   }
   result.push_back(word);

   return result;
}
int main() {

    string str_arr = "baconlettucetomato";


    auto result = ThreeSeparator(str_arr);

    for (auto p : result)
        cout << p << " ";
}