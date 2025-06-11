#include <iostream>
#include <cmath>
using namespace std;

/* 백준 1929 - m부터 n 사이 소수를 모두 출력하는 프로그램 */

/* 소수 구하는 함수 */
bool isPrime(int p){
    if (p==1) return false;
    int cnt = 0;
    int k = sqrt(p); 

    for (int i=1; i<= k; i++){
        if (p%i==0) cnt++;
    }

    if (cnt == 1) return true;
    else return false;
}

int main(void) {
    int n, m;

    cin >> n >> m; //n부터 m까지 숫자 입력
    

    int primecnt = 0;
    for (int i=n; i<=m; i++){
        if (isPrime(i)==true) cout << i << endl;
    }

    return 0;
}