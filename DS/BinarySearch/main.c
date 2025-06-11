#include <stdio.h>

int BSearch(int arr[], int len, int target){

    int first=0;
    int last = len-1;
    int mid;

    while (first<=last){
        mid = (first+last)/2;

        if (target == arr[mid]) return mid; //target값이 중앙에 있으면 target이 있는 idx값 mid 반환함

        else if(target < arr[mid]) last = mid-1;
        else first = mid+1; // tartget > arr[mid]인 경우밖에 안남음
    }

    return -1; //못찾으면 -1 반환
}
int main()
{
    int arr[] = { 1, 3, 5, 7, 9};
    int idx;

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 4); //arr배열, arr배열크기, 찾을 target값

    if (idx == -1) puts("fail to find");
    else printf("target이 저장된 idx는 %d입니다.", idx);

    return 0;
}
