#include <stdio.h>
#define SIZE 4
void combine(int *A, int *B, int *C, int size);

int main(void)
{
    int A[SIZE]={2,5,7,8};
    int B[SIZE]={1,3,4,6};
    int C[SIZE*2]={0};
    int i;
  
    printf("배열A: ");
    for(i=0;i<SIZE;i++)
        printf("%d ", A[i]);
    printf("\n");
  
    printf("배열B: ");
    for(i=0;i<SIZE;i++)
        printf("%d ", B[i]);
    printf("\n");
  
    combine(A,B,C,SIZE);
  
    printf("배열C: ");
    for(i=0;i<SIZE*2;i++)
        printf("%d ", C[i]);
    printf("\n");
  
    return 0;
}

void combine(int A[], int B[], int C[], int size)  // Q.포인터로 바꿔보기
{
  int i = 0;
  int j = 0;
  int k = 0;

while(i<size&&j<size) {

  if (A[i] < B[j]) 
    C[k++] = A[i++];  // 작은값인 A를 C에 복사하고 A의 index만+

  else 
    C[k++] = B[j++];  // 작은값인 B를 C에 복사하고 B의 index만+

}
   
while(i<size){
  C[k++] = A[i++];
  
while(j<size)
  C[k++] = B[j++];

}
}
