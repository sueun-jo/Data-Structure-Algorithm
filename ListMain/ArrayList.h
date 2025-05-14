#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include <stdio.h>
#define TRUE	1
#define FALSE	0

/*** ArrayList****/
#define LIST_LEN	100
typedef int LData;

typedef struct __ArrayList
{
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition; //배열의 인덱스값 (현재 가르키고 있는 위치)
} ArrayList;

typedef ArrayList List;

void ListInit(List * plist){ //초기화
    (plist->numOfData) = 0; // 리스트에 저장된 데이터 수 0
    (plist->curPosition) = -1; //현재 아무 위치도 가리키지 않음, 배열의 인덱스 값이 저장된다
}
void LInsert(List * plist, LData data)//데이터 저장
{
    if (plist->numOfData >= LIST_LEN){
        puts("저장 불가");
        return;
    }

    plist->arr[plist->numOfData] = data; //데이터 저장

}

int LFirst(List * plist, LData * pdata); //첫 데이터 참조
int LNext(List * plist, LData * pdata); //두번째 이후 데이터 참조

LData LRemove(List * plist); //참조한 데이터 삭제
int LCount(List * plist); //저장된 데이터 수 반환

#endif
