#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x, y)   \
do {                 \
  typeof(x) tmp = x; \
  x = y;             \
  y = tmp;           \
} while (0)

int main()
{
    int n;
    printf("please enter a number : \n");
    scanf("%d",&n);
    printf("\n");
    // �إ�n*n�Ӥ����ƪ��r
    int ary[n*n];
    for(int i = 0; i < n*n; i++){
        ary[i] = i+1;
        printf("%d\t",ary[i]);
        if((i+1)%n ==0){
            printf("\n");
        }
    }
    printf("\n");

    // �~�ö���
    srand(time(NULL));
    for(int i = 0; i < n*n; i++) {
        int idx = rand() % (i+1);
        SWAP(ary[idx],ary[i]);
    }

    // new ary
    printf("new array :\n");
    for(int i = 0; i < n*n; i++){
        printf("%d\t",ary[i]);
        if((i+1)%n ==0){
            printf("\n");
        }
    }
    return 0;
}
