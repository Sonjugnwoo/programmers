#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> LeftRight(vector<string>my_string) {
    // "l"의 반복자와 "r"의 반복자를 각각 찾음
    auto l_it = find(my_string.begin(), my_string.end(), "l");
    auto r_it = find(my_string.begin(), my_string.end(), "r");

    // "l"도 "r"도 없는 경우 빈 벡터 반환
    if (l_it == my_string.end() && r_it == my_string.end())
        return {};

    //반복자 직접 비교 
    if (l_it < r_it)
        // "l"이 "r"보다 앞에 있을 경우:
        my_string.erase(l_it, my_string.end());
    else
        // "r"이 "l"보다 앞에 있을 경우:
        my_string.erase(my_string.begin(), r_it + 1);

	return my_string;
}


int main() {
	vector<string> my_string = {  "u","u","l","r"};


	auto result = LeftRight(my_string);
	for(auto p : result)
		cout << p << " ";
	cout << endl;

}