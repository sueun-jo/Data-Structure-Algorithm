#include <iostream>
#include <vector>
using namespace std;

/* 백준 9020 골드 바흐 파티션 */ 

/* 골드바흐 파티션 : 짝수는 반드시 2개의 소수의 덧셈으로 표현 가능하다 */

const int MAX = 1000000;

vector <bool> isPrime (MAX+1, true);

// 에라토스체로 0부터 백만까지 index가 숫자, return타입 bool로 소수 vector 생성
void PrimeFunc(){
    isPrime[0] = isPrime[1] = false;

    for (int i=2; i*i<=MAX; i++)
        if (isPrime[i])
            for (int j=i*i; j<=MAX; j+=i)
                isPrime[j] = false;
}

int main(void){
    PrimeFunc();
    
    //테스트 케이스 갯수 n개 주어지고 입력 받음
    int n; cin >> n;

    int x;
    vector <int> v;

    for (int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);
    }
    
        for (auto k : v){
        int one = k/2;
        int other = k/2;

        while (one >=2){
            if (isPrime[one] && isPrime[other]){
                cout << one << " " << other << "\n";
                break;
            }

            else {
                one--; other++;
            }
        }

    }
    return 0;
}
