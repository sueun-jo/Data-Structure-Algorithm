#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/* 백준 1929 - m부터 n 사이 소수를 모두 출력하는 프로그램 */


int main(void) {
    int m, n;

    cin >> m >> n; //n부터 m까지 숫자 범위 입력
    
    vector <bool> isPrime (n+1, true); //전부 소수라고 가정
    isPrime[0] = isPrime[1] = false; //0이랑 1은 소수 아니니까 false

    for (int i=2; i*i <=n; i++){ //2부터 m까지 소수 찾음
        if (isPrime[i]){
            for (int j=i*i; j<=n; j+=i) isPrime[j] = false;
        }
    }

    //vector isPrime에는 0부터 m까지의 소수 여부 생성
    for (int i=m; i<=n; i++){
        if (isPrime[i]==true) cout << i << "\n";
    }

    return 0;
}