#include <stdio.h>

//삽입정렬로 오름차순 정렬을 만든다
void InsertSort(int arr[], int n){
    int insData;
    int i, j;
    for (i=1; i<n; i++){ //인덱스1부터 n-1(포함)까지 insData가 됨
        insData = arr[i] ; //정렬대상(삽입할 대상)을 insData에 저장

        for ( j = i-1; j>=0; j--){ //arr[j]의 인덱스는  i-1부터 0까지, insData보다 앞에 칸들을 비교하게 됨
            if (arr[j] > insData) //insdata보다 arr[j](insData보다 앞에 있는 데이터)가 큰지 비교해준다
                //arr[j]가 insData보다 크면
                arr[j+1] = arr[j]; //arr[j] 값을 arr[j+1]에 넣어줌 -> 값을 한칸씩 뒤로 밀어준다고 생각하면 된다
            else break; //insData가 insData 앞에 있는 값들보다 크게 될때 빠져나와서
        }
        arr[j+1] = insData; //insData를 arr[j+1]자리에 넣어주게 된다

        //중간에 정렬되는 과정의 배열 출력
        for (int k=0; k<n;k++){
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}
int main()
{
    int arr[5] = {5, 3, 2, 4, 1};

    InsertSort(arr, sizeof(arr)/sizeof(int));

    for (int i=0; i<5; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
