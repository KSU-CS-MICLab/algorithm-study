/**
 * 0의 갯수는 그 전 길이의 0의 갯수
 * 1의 갯수는 그 전 길이의 0~1의 갯수
 * 2의 갯수는 그 전 길이의 0~2의 갯수
 * ....
 * 8의 갯수는 그 전 길이의 0~8의 갯수
 * 9의 갯수는 그 전 길이의 0~9의 갯수
 * d[n][i] = d[n-1][0] + d[n-1][1] + .. + d[n-1][i]
 */
#include <iostream>

using namespace std;

int d[1001][10];

int main() {
    int n;
    long long res=0;
    cin >> n;

    for (int i=0; i<=9; i++) {
        d[1][i] = 1;
    }

    for (int i=2; i<=n; i++) {
        for (int j=0; j<=9; j++) {
            for (int k=0; k<=j; k++) {
                d[i][j] += d[i-1][k];
                d[i][j] %= 10007; 
            }
        }
    }

    for (int i=0; i<=9; i++) {
        res += d[n][i];
    }

    res %= 10007;
    cout << res << '\n';

    return 0;
}