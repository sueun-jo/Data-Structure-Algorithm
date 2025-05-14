#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = (x); (x) = (y); (y) = t;}while(0)

//a[left]~a[right]을 힙으로 만드는 함수
static void downheap (int a[], int left, int right){
    int temp = a[left]; // root
    int child;
    int parent;

    for (parent = left; parent <(right+1)/2; parent=child){
        int cl = parent*2+1; //왼쪽 자식
        int cr = cl+1; //오른쪽 자식

        child = (cr <= right && a[cr] > a[cl]) ? cr : cl; //더 큰 값을 선택함
        if (temp >= a[child])
            break;
        a[parent] = a[child];
    }
    a[parent] = temp;
}

//힙 정렬 함수
void heapsort(int a[], int n){
    int i ;
    for (i = (n-1)/2; i>0; i--){
        swap(int, a[0], a[i]);
        downheap(a, 0, i-1);
    }
}

int main()
{
    int i, nx;
    int *x; //배열을 가르킬 포인터변수

    puts("힙 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i=0; i<nx; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    heapsort(x, nx); //배열 x를 힙정렬
    puts ("오름차순 힙정렬 : ");
    for (i = 0; i<nx; i++){
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x); //배열 동적할당 해제
    return 0;
}
