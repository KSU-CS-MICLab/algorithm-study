
// 변수 설명 : res는 결과값 즉, 레이저에 의해 잘려진 모든 막대의 갯수
//          numberOfSticks는 막대의 갯수 
// 1. ( 또는 ) 오면 스택에 넣는다. 
// 2. ) 가 오면 스택에 쌓여있는 ( 갯수를 하나 빼고 남은 갯수 만큼 막대기가 생긴다. 
//  2-1. 단 스택 꼭대기가 ( 일 경우에만 해당.
//  2-2. 스택 꼭대기가 ) 이면 하나의 막대기가 끝나는 지점이므로 numberOfSticks를 하나 뺴고 res를 하나 추가한다.
//  2-3. 2-2에서 res를 하나 추가하는 이유는 막대의 끝부분이 나왔으니 다음 레이져에 안잘리므로 하나 추가해주는 것이다. 

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int res = 0;
    int numberOfSticks = 0;
    stack<char> parenthesesStk;

    string str;

    cin >> str;
    for (int i=0; i<str.length(); i++) {
        if (str[i] == '(') {
            if (parenthesesStk.size() > 0  && parenthesesStk.top() == '(') {
                numberOfSticks += 1;
            }

            parenthesesStk.push(str[i]);
        } else if (str[i] == ')') {
            char parenthesesStkTop = parenthesesStk.top();
            if (parenthesesStkTop == ')') {
                numberOfSticks -= 1;
                res += 1;
                parenthesesStk.push(str[i]);
            } else if(parenthesesStkTop == '(') {
                res += numberOfSticks;
                parenthesesStk.push(str[i]);
            }
        }
    }

    cout << res; 

    return 0;
}
