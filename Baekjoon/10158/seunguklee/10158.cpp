 /** 
 * [10158]
 * 개미가 움직이면서 WxH 격자공간의 경계면에 부딪치면 만나게되면 방향을 바꾸어 주면 된다.
 * 방향을 바꾸는 것은 경계면을 만났을 때 -1를 곱해주면된다. 
 */

#include <iostream>

using namespace std;

int main() {
    int move_x = 1, move_y = 1;
    int flag = -1;
    int max_x, max_y;
    int pos_x, pos_y;
    int t;

    cin >> max_x >> max_y;
    cin >> pos_x >> pos_y;
    cin >> t;

    while (t--) {
        if (pos_x == max_x || pos_x == 0) move_x *= flag; 
        if (pos_y == max_y || pos_y == 0) move_y *= flag;
        
        pos_x += move_x;
        pos_y += move_y;
    }

    cout << pos_x << ' ' << pos_y ;

    return 0;
}