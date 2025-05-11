#include <stdio.h>

void SelSort(int arr[],int n){ // 정렬할 배열arr과 배열의 크기 n을 매개변수로 넘김

    int minIdx;
    int temp;

    for (int i=0; i<n-1; i++){ //for i 0 to n-1

        minIdx = i;

        //for문 j는 최소값 탐색을 위해서 돌림
        for (int j=i+1; j<n; j++){  // arr[i]랑 arr[j]를 비교해서
            if (arr[j] < arr[minIdx]) //arr[j]가 더 작으면
                minIdx = j; //minIdx를 j로 교환
        }

        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }

}
int main()
{
    int arr[4] = {3, 4, 2, 1};

    SelSort(arr, sizeof(arr)/sizeof(int));

    for (int i=0; i<4; i++)
        printf("%d ", arr[i]);

    return 0;
}


void MySelSort (int arr[], int n){

    //최소값을 찾음
    //찾은걸 교환함

    int min;

    for (int i=0; i<n-1; i++) //n-1번 반복할거임
}
