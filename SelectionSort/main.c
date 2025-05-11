#include <stdio.h>

void SelSort(int arr[],int n){ // 정렬할 배열arr과 배열의 크기 n을 매개변수로 넘김
    int minIdx;
    int temp;

    for (int i=0; i<n-1; i++){ //배열의 총 요소 n개니까 비교는 n-1번만 하면 됨
        minIdx = i;

        //for문 j는 최소값 탐색을 위해서 돌림
        for (int j=i+1; j<n; j++){  // arr[i]랑 arr[j]를 비교해서
            if (arr[j] < arr[minIdx]) //arr[j]가 더 작으면
                minIdx = j; //minIdx를 j로 교환
        }

        temp = arr[i]; //temp에 교환 당할 가장 앞쪽 요소 arr[i]를 저장함
        arr[i] = arr[minIdx]; // arr[i]에 내가 찾은 min값을 저장함
        arr[minIdx] = temp; // 원래 최소값이 있던 자리에 temp값을 넣어 교환 완료
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



