typedef struct HNode *Heap; /* �ѵ����Ͷ��� */
struct HNode {
    ElementType *Data; /* �洢Ԫ�ص����� */
    int Size;          /* ���е�ǰԪ�ظ��� */
    int Capacity;      /* �ѵ�������� */
};
typedef Heap MaxHeap; /* ���� */
typedef Heap MinHeap; /* ��С�� */
 
#define MAXDATA 1000  /* ��ֵӦ���ݾ����������Ϊ���ڶ������п���Ԫ�ص�ֵ */
 
MaxHeap CreateHeap( int MaxSize )
{ /* ��������ΪMaxSize�Ŀյ����� */
 
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->Data = (ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Data[0] = MAXDATA; /* ����"�ڱ�"Ϊ���ڶ������п���Ԫ�ص�ֵ*/
    return H;
}
 
bool IsFull( MaxHeap H )
{
    return (H->Size == H->Capacity);
}
 
bool Insert( MaxHeap H, ElementType X )
{ /* ��Ԫ��X��������H������H->Data[0]�Ѿ�����Ϊ�ڱ� */
    int i;
    if ( IsFull(H) ) { 
        printf("��������");
        return false;
    }
    i = ++H->Size; /* iָ��������е����һ��Ԫ�ص�λ�� */
    for ( ; H->Data[i/2] < X; i/=2 )
        H->Data[i] = H->Data[i/2]; /* ����X */
    H->Data[i] = X; /* ��X���� */
    return true;
}
 
#define ERROR -1 /* �����ʶӦ���ݾ����������Ϊ���в����ܳ��ֵ�Ԫ��ֵ */
 
bool IsEmpty( MaxHeap H )
{
    return (H->Size == 0);
}
 
ElementType DeleteMax( MaxHeap H )
{ /* ������H��ȡ����ֵΪ����Ԫ�أ���ɾ��һ����� */
    int Parent, Child;
    ElementType MaxItem, X;
 
    if ( IsEmpty(H) ) {
        printf("������Ϊ��");
        return ERROR;
    }
 
    MaxItem = H->Data[1]; /* ȡ��������ŵ����ֵ */
    /* �����������һ��Ԫ�شӸ���㿪ʼ���Ϲ����²��� */
    X = H->Data[H->Size--]; /* ע�⵱ǰ�ѵĹ�ģҪ��С */
    for( Parent=1; Parent*2<=H->Size; Parent=Child ) {
        Child = Parent * 2;
        if( (Child!=H->Size) && (H->Data[Child]<H->Data[Child+1]) )
            Child++;  /* Childָ�������ӽ��Ľϴ��� */
        if( X >= H->Data[Child] ) break; /* �ҵ��˺���λ�� */
        else  /* ����X */
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
    return MaxItem;
} 
 
/*----------- �������� -----------*/
void PercDown( MaxHeap H, int p )
{ /* ���ˣ���H����H->Data[p]Ϊ�����Ӷѵ���Ϊ���� */
    int Parent, Child;
    ElementType X;
 
    X = H->Data[p]; /* ȡ��������ŵ�ֵ */
    for( Parent=p; Parent*2<=H->Size; Parent=Child ) {
        Child = Parent * 2;
        if( (Child!=H->Size) && (H->Data[Child]<H->Data[Child+1]) )
            Child++;  /* Childָ�������ӽ��Ľϴ��� */
        if( X >= H->Data[Child] ) break; /* �ҵ��˺���λ�� */
        else  /* ����X */
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
}
 
void BuildHeap( MaxHeap H )
{ /* ����H->Data[]�е�Ԫ�أ�ʹ�������ѵ�������  */
  /* �����������H->Size��Ԫ���Ѿ�����H->Data[]�� */
 
    int i;
    /* �����һ�����ĸ��ڵ㿪ʼ���������1 */
    for( i = H->Size/2; i>0; i-- )
        PercDown( H, i );
}