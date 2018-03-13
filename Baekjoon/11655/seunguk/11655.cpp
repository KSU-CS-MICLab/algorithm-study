/**
 * [11655]
 * 원형 큐가 있다고 생각하여 풀자.
 * 알파벳은 총 26개 -> 26의 크기를 가진 원형큐가 있다.
 * 현재 위치에서 13칸 만큼 앞으로 가면 된다. (next_step) 
 */ 

#include <iostream>
#include <queue>

using namespace std;

int next_step(int now, int len, int count);

int main() {
    int length = 26;
    int rot = 13;

    string str;
    getline(cin, str);
    for (int i=0; i<str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = next_step(str[i]-'a', length, rot) + 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = next_step(str[i]-'A', length, rot) + 'A';
        }         
    }
    cout << str;
    return 0;
}

int next_step(int now, int len, int count)
{ //길이가 len인 원형 판에서 
  // now번 칸에 서 있을 때 count 칸 만큼 전진하면
  // 서 있게 되는 칸의 번호 계산하기
  return ( now + count ) % len;  
}