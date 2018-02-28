/**
 * [1463]
 * DP[i] = i를 1로 만들수 있는 최소값.
 * 
 * 1. i가 3으로 나누어 질때 
 *  count = D[i/3] + 1
 *  if D[i] > count : D[i] = count 
 * 
 * 2. i가 2로 나누어 질때
 *  count = D[i/2] + 1
 *  if D[i] > count : D[i] = count 
 * 
 * 3. i를 1만큼 뺄 경우
 *  D[i] = D[i-1] + 1
 *  
 */ 

#include <iostream>

using namespace std;

int Count_MakeItOne(int num);

int DP[1000001];

int main() {
    int num;
    int count = 0;
    int res;

    cin >> num;
    
    res = Count_MakeItOne(num);
    cout << res;

    return 0;
}

int Count_MakeItOne(int num) {
    if (num == 1) return 0;
    if (DP[num] > 0) return DP[num];

    DP[num] = Count_MakeItOne(num-1) + 1;
    
    if (num%2 == 0) {
        int count = Count_MakeItOne(num/2) + 1;
        if (DP[num] > count) DP[num] = count;
    }
    
    if (num%3 == 0) {
        int count = Count_MakeItOne(num/3) + 1;
        if (DP[num] > count) DP[num] = count;
    }
    return DP[num];
}