/* �������� - ֱ�ӵ��ÿ⺯�� */
 
#include <stdlib.h>
 
/*---------------����������--------------------*/
int compare(const void *a, const void *b)
{ /* �Ƚ����������ǽ������� */
    return (*(int*)a - *(int*)b);
}
/* ���ýӿ� */ 
qsort(A, N, sizeof(int), compare);
/*---------------����������--------------------*/
 
 
/*--------------- һ������£��Խṹ��Node�е�ĳ��ֵkey���� ---------------*/
struct Node {
    int key1, key2;
} A[MAXN];
  
int compare2keys(const void *a, const void *b)
{ /* �Ƚ����ּ�ֵ����key1���������У����key1��ȣ���key2�ǽ������� */
    int k;
    if ( ((const struct Node*)a)->key1 < ((const struct Node*)b)->key1 )
        k = 1;
    else if ( ((const struct Node*)a)->key1 > ((const struct Node*)b)->key1 )
        k = -1;
    else { /* ���key1��� */
        if ( ((const struct Node*)a)->key2 < ((const struct Node*)b)->key2 )
            k = -1;
        else
            k = 1;
    }
    return k;
}
/* ���ýӿ� */ 
qsort(A, N, sizeof(struct Node), compare2keys);
/*------ һ������£��Խṹ��Node�е�ĳ��ֵkey���� --------*/


/***************�ָ���******************/

ElementType Median3( ElementType A[], int Left, int Right )
{ 
    int Center = (Left+Right) / 2;
    if ( A[Left] > A[Center] )
        Swap( &A[Left], &A[Center] );
    if ( A[Left] > A[Right] )
        Swap( &A[Left], &A[Right] );
    if ( A[Center] > A[Right] )
        Swap( &A[Center], &A[Right] );
    /* ��ʱA[Left] <= A[Center] <= A[Right] */
    Swap( &A[Center], &A[Right-1] ); /* ����׼Pivot�ص��ұ�*/
    /* ֻ��Ҫ����A[Left+1] �� A[Right-2] */
    return  A[Right-1];  /* ���ػ�׼Pivot */
}
 
void Qsort( ElementType A[], int Left, int Right )
{ /* ���ĵݹ麯�� */ 
     int Pivot, Cutoff, Low, High;
       
     if ( Cutoff <= Right-Left ) { /* �������Ԫ�س�ֶ࣬������� */
          Pivot = Median3( A, Left, Right ); /* ѡ��׼ */ 
          Low = Left; High = Right-1;
          while (1) { /*�������бȻ�׼С���Ƶ���׼��ߣ�����Ƶ��ұ�*/
               while ( A[++Low] < Pivot ) ;
               while ( A[--High] > Pivot ) ;
               if ( Low < High ) Swap( &A[Low], &A[High] );
               else break;
          }
          Swap( &A[Low], &A[Right-1] );   /* ����׼������ȷ��λ�� */ 
          Qsort( A, Left, Low-1 );    /* �ݹ������ */ 
          Qsort( A, Low+1, Right );   /* �ݹ����ұ� */  
     }
     else InsertionSort( A+Left, Right-Left+1 ); /* Ԫ��̫�٣��ü����� */ 
}
 
void QuickSort( ElementType A[], int N )
{ /* ͳһ�ӿ� */
     Qsort( A, 0, N-1 );
}