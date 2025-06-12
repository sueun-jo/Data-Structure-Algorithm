#include <iostream>
#include <vector>
using namespace std;

/* 골드 바흐 파티션 갯수 구하는 문제*/
/* 첫째줄에 테스트 케이스 갯수 주어짐 */
/* 주어진 테스트 케이스의 골드바흐 파티션 갯수 return 하여 출력*/
const int MAX = 1000000;
vector <bool> isPrime (MAX+1, true);
void makePrimeVector(){
    
    isPrime[0] = isPrime[1] = false;

    for (int i=2; i*i<=MAX; i++)
        if (isPrime[i])
            for (int j=i*i; j<=MAX; j+=i)
                isPrime[j] = false;

}

int main (void) {
    makePrimeVector();

    int n;
    cin >> n; 

    int x; vector <int> v;
    
    for (int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);
    }

    //vector 값 순회하면서 partition 갯수 cnt
    for (auto k : v){
        
        int one = k/2;
        int other = k/2;
        
        int cnt= 0;

        while (one>=2){
            if (isPrime[one] && isPrime[other]){
                cnt++; //파티션cnt 갯수 증가
            }
            else {
                one--; other++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}