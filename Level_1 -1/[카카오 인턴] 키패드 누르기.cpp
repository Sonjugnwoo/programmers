#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<int> key_path = { 1,2,3,4,5,6,7,8,9,0 ,10,12};
    int right_num = 12;
    int left_num =10;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            left_num = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            right_num = numbers[i];
        }
        else {
            auto pos = find(key_path.begin(), key_path.end(), numbers[i]);
            int right_pos = abs(distance(pos, find(key_path.begin(), key_path.end(), right_num)));
            int left_pos = abs(distance(pos, find(key_path.begin(), key_path.end(), left_num)));

          
      
            if (right_pos > left_pos) {
                answer += "L";
                left_num = numbers[i];
            }
            else if (right_pos < left_pos) {
                answer += "R";
                right_num = numbers[i];
            }
            else {
                if (hand == "right")
                    answer += "R";
                else
                    answer += "L";
            }
                
        }

   }

    return answer;
}

int main() {
    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string hand = "right";

    auto result = solution(numbers,hand);

    cout << result << endl;
}

