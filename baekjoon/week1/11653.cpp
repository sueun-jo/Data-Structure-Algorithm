#include <iostream>
#include <vector>
using namespace std;

/* 백준 11653 소인수분해 */
const int MAX = 1000000;
vector <int> isPrime (MAX+1, true);

/* 에라체 */
void seive(){
    isPrime[0] = isPrime[1] = false;

    for (int i=2; i*i<=MAX; i++){
        if (isPrime[i])
            for (int j=i*i; j<=MAX; j+=i)
                isPrime[j]  = false;
    }
}

int main(void){
    
    seive();
    int n;
    cin >> n;

    while (1){
        if (n==1) break; //n이 1이 되면 탈출

        for (int i=2; i<=n; ){
                if (n%i==0) {

                    // cout << "[debug] i = ";
                    cout << i << "\n";
                    n = n/i;
                    // cout << "[debug] n = " << n << "\n";
                }
                else i++;
        }
    }
    
    
    return 0;
}

