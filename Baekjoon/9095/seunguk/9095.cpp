 /** 
 * [9095]
 * d[n] = d[n-1] + d[n-2] + d[n-3]
 */

#include <iostream>

using namespace std;

int Add123(int n);

int d[1001];

int main() {
    int num;
    int t;

    cin >> t;
    while (t--) {
        cin >> num;
        cout << Add123(num) << '\n';
    }
    
    return 0;
}

int Add123(int n) {
    if (n == 1) return 1;
    else if (n == 2) return 2;
    else if (n == 3) return 4;
    else {
        if (d[n] > 0) return d[n];
        d[n] = Add123(n-1) + Add123(n-2) + Add123(n-3);
        return d[n];
    }
}