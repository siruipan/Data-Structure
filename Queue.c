//*******队列的顺序存储******
typedef int Position;
struct QNode {
    ElementType *Data;     /* 存储元素的数组 */
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量 */
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
        printf("队列满");
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
        printf("队列空");
        return ERROR;
    }
    else  {
        Q->Front =(Q->Front+1)%Q->MaxSize;
        return  Q->Data[Q->Front];
    }
}

//********队列的链式存储*****
//AddQ函数、CreatQueue函数edit by myself
typedef struct Node *PtrToNode;
struct Node { /* 队列中的结点 */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;
 
struct QNode {
    Position Front;
    Position Rear;  /* 队列的头、尾指针 */
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
        printf("队列空");
        return ERROR;
    }
    else {
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) /* 若队列只有一个元素 */
            Q->Front = Q->Rear = NULL; /* 删除后队列置为空 */
        else                     
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;
        free( FrontCell );  /* 释放被删除结点空间  */
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