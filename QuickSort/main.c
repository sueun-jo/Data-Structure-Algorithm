#include <stdio.h>
//값 교환을 위한 Swap 함수
void Swap (int arr[], int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition (int arr[], int left, int right){
    int pivot = arr[left]; //피벗 위치는 제일 왼쪽으로 잡는다
    int low = left+1;
    int high = right;

    while (low <= high){ //교차되지 않을 때까지 반복한다

        // pivot보다 큰 값을 찾는 과정
        while (pivot >= arr[low] && low <= right) //low가 주어진 배열을 넘어가지 않도록
            low++; //low를 오른쪽으로 이동

        // pivot보다 작은 값을 찾는 과정
        while (pivot <= arr[high] && high >= (left+1)) //high가 주어진 배열을 넘어가지 않도록
            high--; // high를 왼쪽으로 이동

        if (low <= high)
            Swap (arr, low, high);
    }
    //while문을 빠져나오면 low > high로 엇갈렸음
    Swap (arr, left, high); //pivot과 high가 가리키는 대상 교환
    return high; //옮겨진 pivot값 (제자리를 찾은 pivot값) 을 반환
}

void QuickSort(int arr[], int left, int right){
    if (left <= right){
        int pivot = Partition (arr, left, right); //둘로 나눠서
        QuickSort(arr, left, pivot-1); //왼쪽 영역 정렬
        QuickSort(arr, pivot+1, right); // 오른쪽 영역 정렬
    }
}
int main(void){

    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    // int arr[3] = {3, 3, 3};

    int len = sizeof(arr) / sizeof(int);

    //QuickSort 실행
    QuickSort(arr, 0, len-1);

    //정렬된 배열 출력
    for (int i=0; i<len; i++)
        printf("%d ", arr[i]);

    return 0;
}
