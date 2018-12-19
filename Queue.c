//*******���е�˳��洢******
typedef int Position;
struct QNode {
    ElementType *Data;     /* �洢Ԫ�ص����� */
    Position Front, Rear;  /* ���е�ͷ��βָ�� */
    int MaxSize;           /* ����������� */
};
typedef struct QNode *Queue;
 
Queue CreateQueue( int MaxSize )
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}
 
bool IsFull( Queue Q )
{
    return ((Q->Rear+1)%Q->MaxSize == Q->Front);
}
 
bool AddQ( Queue Q, ElementType X )
{
    if ( IsFull(Q) ) {
        printf("������");
        return false;
    }
    else {
        Q->Rear = (Q->Rear+1)%Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}
 
bool IsEmpty( Queue Q )
{
    return (Q->Front == Q->Rear);
}
 
ElementType DeleteQ( Queue Q )
{
    if ( IsEmpty(Q) ) { 
        printf("���п�");
        return ERROR;
    }
    else  {
        Q->Front =(Q->Front+1)%Q->MaxSize;
        return  Q->Data[Q->Front];
    }
}

//********���е���ʽ�洢*****
//AddQ������CreatQueue����edit by myself
typedef struct Node *PtrToNode;
struct Node { /* �����еĽ�� */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;
 
struct QNode {
    Position Front;
    Position Rear;  /* ���е�ͷ��βָ�� */
};
typedef struct QNode *Queue;

Queue CreateQueue(){
    Queue Q;
    Q=(Queue)malloc(sizeof(struct QNode));
    Q->Front=Q->Rear=NULL;
}
 
bool IsEmpty( Queue Q )
{
    return ( Q->Front == NULL);
}
 
ElementType DeleteQ( Queue Q )
{
    Position FrontCell;
    ElementType FrontElem;
     
    if  ( IsEmpty(Q) ) {
        printf("���п�");
        return ERROR;
    }
    else {
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) /* ������ֻ��һ��Ԫ�� */
            Q->Front = Q->Rear = NULL; /* ɾ���������Ϊ�� */
        else                     
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;
        free( FrontCell );  /* �ͷű�ɾ�����ռ�  */
        return  FrontElem;
    }
}

void AddQ(Queue Q,ElementType X){
    Position node=(Position)malloc(sizeof(struct Node));
    node->Next=NULL;
    node->Data=X;
    if(IsEmpty(Q)){
        Q->Front=Q->Rear=node;
    }
    else{
        Q->Rear->Next=node;
        Q->Rear=node;
    }
    return;
}