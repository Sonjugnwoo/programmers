#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countSmallerSubstrings(string t, string p) {
    int answer = 0;
    // t의 각 인덱스에서 시작하는 부분 문자열 검사
    for (int i = 0; i < t.size(); i++) {
        // i에서 시작해 p의 길이만큼 잘라낸 부분 문자열
        auto str = t.substr(i, p.size());

        // 부분 문자열의 길이가 p와 같고, 문자열 비교로 p보다 작거나 같을 경우 카운트
        if (str.size() == p.size() && str <= p)
            answer++;
    }

    return answer;
    return answer;
}

int main()
{
    string t = "3141592";
    string p = "271";
    auto result = countSmallerSubstrings(t,p);
   
    cout << result << endl;
}
