/**
 * 0의 갯수는 그 전 길이의 1의 갯수
 * 1의 갯수는 그 전 길이의 0,2의 갯수
 * 2의 갯수는 그 전 길이의 1,3의 갯수
 * ....
 * 8의 갯수는 그 전 길이의 7,9의 갯수
 * 9의 갯수는 그 전 길이의 8의 갯수
 * d[i][j] = (d[i-1][j-1]) + (d[i-1][j+1]); 
 */
#include <iostream>

using namespace std;

int d[101][10];

int main() {
    int n;
    long long res=0;
    cin >> n;

    d[1][0] = 0;
    for (int i=1; i<=9; i++) {
        d[1][i] = 1;
    }

    for (int i=2; i<=n; i++) {
        d[i][0] = d[i-1][1];
        d[i][9] = d[i-1][8];
        for (int j=1; j<=8; j++) {
            d[i][j] = (d[i-1][j-1]%1000000000) + (d[i-1][j+1]%1000000000); 
        }
    }
    
    for (int i=0; i<=9; i++) {
        res += d[n][i];
    } 
    res %= 1000000000;

    cout << res << '\n';

    return 0;
}