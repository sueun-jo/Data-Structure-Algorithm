#include <stdio.h>

int main(void){
    int heap[9] = {7, 6, 5, 8, 3, 5, 9, 1, 6};
    int number = sizeof(heap)/sizeof(int); // 9값이 나온다


    //우선, 트리 구조를 최대 힙 구조로 바꾼다
    for (int i=1; i<number; i++){
        int c = i;

        do{
            int root = (c-1)/2; //자기 자신의 부모 Idx를 구함
            if (heap[root] < heap[c]){ //자식값이 부모값보다 크면
                int temp = heap[root]; //위치 교환
                heap[root] = heap[c];
                heap[c] = temp;
            }

            c = root; //자식의 부모로 이동해서 반복적으로 수행함

        } while (c != 0);
    }

    //크기를 줄여가면서 반복적으로 힙을 구성
    for (int i= number-1; i>=0; i--){
        int temp = heap[0]; //heap[0]에 있는 최대값을
        heap[0] = heap[i]; //마지막 idx값이랑
        heap[i] = temp;    //바꿔주는 작업
        int root = 0;
         int c;

        do {
            c = 2*root + 1;
            //자식 중에 더 큰 값 찾기
            if ( heap[c] < heap [c+1] && c < i-1 ) // (조건1) : c가 i-1 범위 못벗어남
                c++; // heap[c] < heap[c+1]이면 c에 1을 더해서 비교할 자식 c를 heap[c+1]로 만드는거임

            //루트보다 자식이 더 크면 루트<->자식
            if (heap[root] < heap[c] &&  c < i ){
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }

            root = c;
        } while (c<i);
    }

    //결과 출력
    for (int i=0; i<number; i++)
        printf("%d ", heap[i]);

}
