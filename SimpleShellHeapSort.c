/************冒泡排序**********/
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
		if(flag==0) break;  //全程无交换
	}
}

/*************插入排序*********/
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

/***********希尔排序************/
void ShellSort( ElementType A[], int N )
{ /* 希尔排序 - 用Sedgewick增量序列 */
	int Si, D, P, i;
	ElementType Tmp;
	/* 这里只列出一小部分增量 */
	int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

	for ( Si=0; Sedgewick[Si]>=N; Si++ ) 
	 ; /* 初始的增量Sedgewick[Si]不能超过待排序列长度 */

	for ( D=Sedgewick[Si]; D>0; D=Sedgewick[++Si] )
	 for ( P=D; P<N; P++ ) { /* 插入排序*/
	     Tmp = A[P];
	     for ( i=P; i>=D && A[i-D]>Tmp; i-=D )
	         A[i] = A[i-D];
	     A[i] = Tmp;
	}
}

/************堆排序****************/
void Swap( ElementType *a, ElementType *b )
{
     ElementType t = *a; *a = *b; *b = t;
}
  
void PercDown( ElementType A[], int p, int N )
{ /* 改编代码4.24的PercDown( MaxHeap H, int p )    */
  /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    ElementType X;
 
    X = A[p]; /* 取出根结点存放的值 */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= A[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}
 
void HeapSort( ElementType A[], int N ) 
{ 
     int i;
       
     for ( i=N/2-1; i>=0; i-- )/* 建立最大堆 */
         PercDown( A, i, N );
      
     for ( i=N-1; i>0; i-- ) {
         /* 删除最大堆顶 */
         Swap( &A[0], &A[i] ); 
         PercDown( A, 0, i );
     }
}