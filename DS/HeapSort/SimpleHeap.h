#ifndef SIMPLEHEAP_H
#define SIMPLEHEAP_H

#define TRUE 0
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

//힙의 저장될 데이터의 모델을 정의한 구조체
typedef struct _heapElem{
    Priority pr; //값이 작을 수록 높은 우선 순위
    HData data;
} HeapElem;

typedef struct _heap
{
    int numofData;
    HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);

void HInsert(Heap *poh, HData data, Priority pr);
HData HDelete(Heap *ph);


#endif // SIMPLEHEAP_H
