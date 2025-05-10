#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x= y; y = t;} while (0)
// 위 문장은 swap 매크로로 요소값을 바꿔주는 역할을 한다

#define ON 1
#define OFF 0

#if OFF /*버블정렬 기본버전*/
void BubbleSort(int arr[], int n){ //연산할 배열과 요소가 몇개 있는지에 대한 정보를 넘겨줌

    for (int i=0; i<n-1; i++){ // 비교할 요소가 n개면 n-1번 비교하게 됨
        for (int j = n-1; j > i; j--){
            if (arr[j-1] > arr[j]) // arr[n-2]와 arr[n-1] 비교했을 때 앞에 꺼가 더 크면
                swap(int, arr[j-1], arr[j]); //앞에꺼(큰거)랑 뒤에꺼(작은거)를 바꿔줌
        }
    }
}
int main()
{
    int nx; // 비교할 요소 갯수

    puts ("버블정렬"); //개행이 자동으로 되도록 단순 문자열 출력
    printf("요소 갯수: ");
    scanf ("%d", &nx);

    int* x = (int *) calloc (nx, sizeof(int));
    //배열 첫번째 요소를 가르킬 포인터 변수 x 선언과, nx만큼의 동적 할당
    for (int i=0; i< nx; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]); // 배열 요소를 사용자로부터 입력받게 됨
    }

    BubbleSort (x, nx); //bubble정렬 실행

    puts("오름차순으로 bubble sort 실행완료");
    for (int i=0; i<nx; i++){
        printf("x[%d] = %d\n", i, x[i]); //실행값 출력함
    }

    free(x);

    return 0;
}
#endif

#if OFF /*앞에서부터 요소를 비교해나가는 오름차순 bubble정렬*/
/*교환하고 비교하는 횟수까지 출력함*/

void Bubble2 (int arr[], int n, int *Comp, int *Change) {

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){
            (*Comp)++; //비교값 증가
            if (arr[j]>arr[j+1]) //앞에가 뒤에보다 크면
            {
                swap(int, arr[j], arr[j+1]);
                (*Change)++; //change값 증가
            } //앞에값을 뒤로 옮겨줌

        }
    }
}


int main(void){

    puts("버블정렬 연습문제1 (앞에서부터 비교해나가는 버전)");
    printf("요소 개수 : ");
    int nx; //요소 개수 담을 변수
    scanf("%d", &nx);

    int *x = (int *) malloc (sizeof(int) * nx); //nx크기만큼의 int형 배열 동적할당

    for (int i=0; i<nx; i++){
        printf("arr[%d] : ", i);
        scanf("%d",&x[i]);
    } //배열 사용자로부터 마구마구 입력받음

    int CompareCnt = 0; //compare횟수
    int ChangeCnt = 0; //cnt횟수
    Bubble2(x, nx, &CompareCnt, &ChangeCnt); //주소값 넘겨서 Bubble함수에서 포인터 변수랑 만날거임

    puts("오름차순 bubble2 실행 후 결과값");
    for (int i=0; i<nx; i++)
        printf("arr[%d] : %d\n", i, x[i]);

    printf("비교는 %d회, 교환은 %d회 했습니다", CompareCnt, ChangeCnt);
    free(x); //메모리 할당 해제
    return 0;
}
#endif

#if ON /* 열혈 자료구조 속 bubble sort*/
void Bubble3 (int arr[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j < n-1-i; j++){
            if (arr[j]>arr[j+1]) //앞에가 뒤에보다 크면
                swap(int, arr[j], arr[j+1]); //swap
        }
    }
}

int main(void){

    int arr[4] = {3, 2, 4, 1};

    Bubble3(arr, sizeof(arr)/sizeof(int));

    for (int i=0; i<4; i++)
        printf("%d ", arr[i]);

    return 0;
}
#endif
