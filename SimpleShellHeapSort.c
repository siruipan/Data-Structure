/************ð������**********/
void Bubble_Sort(ElementType A[],int N){
	int i,P;
	for(P=N-1;P>=0;P--){
		int flag=0;
		for(i=0;i<P;i++){
			if(A[i]>A[i+1]){
				Swap(A[i],A[i+1]);
				flag=1;
			}
		}
		if(flag==0) break;  //ȫ���޽���
	}
}

/*************��������*********/
void Insertion_Sort(ElementType A[],int N){
	int P,i;
	ElementType tmp;
	for(P=1;P<N;P++){
		tmp=A[P];
		for(i=P;i>0&&A[i-1]>tmp;i--)
			A[i]=A[i-1];
		A[i]=tmp;
	}
}

/***********ϣ������************/
void ShellSort( ElementType A[], int N )
{ /* ϣ������ - ��Sedgewick�������� */
	int Si, D, P, i;
	ElementType Tmp;
	/* ����ֻ�г�һС�������� */
	int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

	for ( Si=0; Sedgewick[Si]>=N; Si++ ) 
	 ; /* ��ʼ������Sedgewick[Si]���ܳ����������г��� */

	for ( D=Sedgewick[Si]; D>0; D=Sedgewick[++Si] )
	 for ( P=D; P<N; P++ ) { /* ��������*/
	     Tmp = A[P];
	     for ( i=P; i>=D && A[i-D]>Tmp; i-=D )
	         A[i] = A[i-D];
	     A[i] = Tmp;
	}
}

/************������****************/
void Swap( ElementType *a, ElementType *b )
{
     ElementType t = *a; *a = *b; *b = t;
}
  
void PercDown( ElementType A[], int p, int N )
{ /* �ı����4.24��PercDown( MaxHeap H, int p )    */
  /* ��N��Ԫ�ص���������A[p]Ϊ�����Ӷѵ���Ϊ���� */
    int Parent, Child;
    ElementType X;
 
    X = A[p]; /* ȡ��������ŵ�ֵ */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Childָ�������ӽ��Ľϴ��� */
        if( X >= A[Child] ) break; /* �ҵ��˺���λ�� */
        else  /* ����X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}
 
void HeapSort( ElementType A[], int N ) 
{ 
     int i;
       
     for ( i=N/2-1; i>=0; i-- )/* �������� */
         PercDown( A, i, N );
      
     for ( i=N-1; i>0; i-- ) {
         /* ɾ�����Ѷ� */
         Swap( &A[0], &A[i] ); 
         PercDown( A, 0, i );
     }
}