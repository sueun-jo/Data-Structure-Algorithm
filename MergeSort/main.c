#include <stdio.h>
#include <stdlib.h>

void Merge (int arr[], int left, int mid, int right){
    int fIdx = left; //fIdx는 frontIndex로 왼쪽부분의 첫 시작점 idx값
    int rIdx = mid+1; //rIdx는 rearIndex로 오른쪽 부분의 첫 시작점 idx값


    int * sortArr = (int *)malloc(sizeof(int)*(right+1)); // 병합 결과를 담을 임시 배열 sortArr을 동적 할당
    int sIdx = left; //sIdx는 임시배열의 위치, sortedIdx로 정렬된 값을 저장할 위치를 알려줄게용


    while (fIdx <= mid && rIdx <= right){
        if (arr[fIdx] <= arr[rIdx]) // merge할 두 영역의 데이터들을 비교하여 arr[fIdx] <= arr[rIdx]면
            sortArr[sIdx] = arr[fIdx++]; //임시배열 sIdx에 arr[fIdx]값 담은 뒤 fIdx에 1 늘림 (다음 Idx로 이동)
        else                        // arr[fIdx] > arr[rIdx]면
            sortArr[sIdx] = arr[rIdx++]; //임시배열 sIdx에 arr[rIdx]값 담은 후 rIdx에 1 늘려준다 (다음 Idx로 이동)

        sIdx++; // sortArr[sIdx]에 값을 담고 나면 다음 값을 담을 수 있도록 sIdx += 1;
    }

    if (fIdx > mid){               //배열 앞부분이 모두 sortArr에 옮겨지면 fIdx가 mid를 넘어서게 되면, 앞부분 배열은 이미 다 갖다씀
        for (int i=rIdx; i<=right; i++, sIdx++)
            sortArr[sIdx] = arr[i];//배열 뒷부분에 남은 데이터들을 (rIDx~right까지 )sortArr에 담아줌
    }

    else                          //배열 뒷부분이 모두 sortArr에 옮겨지면
    {
        for (int i=fIdx; i<=mid; i++, sIdx++) //배열 앞부분에 남은 데이터들 (fIdx~mid까지)
        {
            sortArr[sIdx] = arr[i]; //배열 앞부분에 남은 데이터들을 sortArr에 옮김
        }

    }

    for (int i = left; i<=right; i++)
        arr[i] = sortArr[i]; //임시배열 sortArr을 원래 있던 arr로 옮겨줌

    free (sortArr); //sortArr동적할당 했던 것 free
}

void Divide(int arr[], int left, int right){
    int mid;

    if (left < right){ //left가 right보다 작다는 건 더 나눌 수 있다는 뜻이다
        mid = (left+right)/2; //중간지점 계산 = 반갈죽 준비

        Divide(arr, left, mid); //반갈죽의 왼쪽 부분 (left~mid)을 divide 해라
        Divide(arr, mid+1, right); //반갈죽의 오른쪽을 (mid+1~right)을 divide해라

        //divide된 애들 merge해라
        Merge(arr, left, mid, right);
    }
}
int main()
{
    int arr[10] = {3, 2, 4, 1, 7, 6, 5, 10, 15, 13};

    //배열 arr의 전체 영역 정렬
    Divide(arr, 0, sizeof(arr)/sizeof(int)-1); // 배열 arr을, 인덱스 0부터 인덱스 끝까지(배열길이-1) 정렬해라

    for (int i=0; i<10; i++) //정렬 끝난 배열 출력하는 부분
        printf("%d ", arr[i]);

    return 0;
}
