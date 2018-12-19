/* �鲢���� - �ݹ�ʵ�� */
 
/* L = �����ʼλ��, R = �ұ���ʼλ��, RightEnd = �ұ��յ�λ��*/
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
{ /* �������A[L]~A[R-1]��A[R]~A[RightEnd]�鲢��һ���������� */
     int LeftEnd, NumElements, Tmp;
     int i;
      
     LeftEnd = R - 1; /* ����յ�λ�� */
     Tmp = L;         /* �������е���ʼλ�� */
     NumElements = RightEnd - L + 1;
      
     while( L <= LeftEnd && R <= RightEnd ) {
         if ( A[L] <= A[R] )
             TmpA[Tmp++] = A[L++]; /* �����Ԫ�ظ��Ƶ�TmpA */
         else
             TmpA[Tmp++] = A[R++]; /* ���ұ�Ԫ�ظ��Ƶ�TmpA */
     }
 
     while( L <= LeftEnd )
         TmpA[Tmp++] = A[L++]; /* ֱ�Ӹ������ʣ�µ� */
     while( R <= RightEnd )
         TmpA[Tmp++] = A[R++]; /* ֱ�Ӹ����ұ�ʣ�µ� */
          
     for( i = 0; i < NumElements; i++, RightEnd -- )
         A[RightEnd] = TmpA[RightEnd]; /* �������TmpA[]���ƻ�A[] */
}
 
void Msort( ElementType A[], ElementType TmpA[], int L, int RightEnd )
{ /* ���ĵݹ������� */ 
     int Center;
      
     if ( L < RightEnd ) {
          Center = (L+RightEnd) / 2;
          Msort( A, TmpA, L, Center );              /* �ݹ������ */ 
          Msort( A, TmpA, Center+1, RightEnd );     /* �ݹ����ұ� */  
          Merge( A, TmpA, L, Center+1, RightEnd );  /* �ϲ������������� */ 
     }
}
 
void MergeSort( ElementType A[], int N )
{ /* �鲢���� */
     ElementType *TmpA;
     TmpA = (ElementType *)malloc(N*sizeof(ElementType));
      
     if ( TmpA != NULL ) {
          Msort( A, TmpA, 0, N-1 );
          free( TmpA );
     }
     else printf( "�ռ䲻��" );
}


/***************�ָ���****************/
/* �鲢���� - ѭ��ʵ�� */
/* ����Merge�����ڵݹ�汾�и��� */
 
/* length = ��ǰ�������еĳ���*/
void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length )
{ /* �����鲢������������ */
     int i, j;
       
     for ( i=0; i <= N-2*length; i += 2*length )
         Merge( A, TmpA, i, i+length, i+2*length-1 );
     if ( i+length < N ) /* �鲢���2������*/
         Merge( A, TmpA, i, i+length, N-1);
     else /* ���ֻʣ1������*/
         for ( j = i; j < N; j++ ) TmpA[j] = A[j];
}
 
void Merge_Sort( ElementType A[], int N )
{ 
     int length; 
     ElementType *TmpA;
      
     length = 1; /* ��ʼ�������г���*/
     TmpA = malloc( N * sizeof( ElementType ) );
     if ( TmpA != NULL ) {
          while( length < N ) {
              Merge_pass( A, TmpA, N, length );
              length *= 2;
              Merge_pass( TmpA, A, N, length );
              length *= 2;
          }
          free( TmpA );
     }
     else printf( "�ռ䲻��" );
}