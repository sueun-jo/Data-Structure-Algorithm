#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* 소수 구하는 함수 */
bool isPrime(int p){
    if (p==1) return false;
    int cnt = 0;
    int k = sqrt(p); //형변환 연산자로 제곱근 갈기기

    for (int i=1; i<= k; i++){
        if (p%i==0) cnt++;
    }

    if (cnt == 1) return true;
    else return false;
}

int main(void) {
    int n;
    cin >> n; //n번 입력받음

    vector <int> v;
    int x;
    for (int i = 0; i < n; i++) {
         cin >> x;
         v.push_back(x); //x값 vector에 집어 넣기
    }

    //현재까지 vector엔 소수인지 아닌지 판별해야 하는 값이 들어가 있음

    int primecnt = 0;
    for (auto k : v){
        if (isPrime(k)==true) primecnt++;
    }

    cout << primecnt;

    return 0;
}