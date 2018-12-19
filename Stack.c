//********ջ��˳��洢ʵ�ּ�����******
typedef int Position;
struct SNode {
    ElementType *Data; /* �洢Ԫ�ص����� */
    Position Top;      /* ջ��ָ�� */
    int MaxSize;       /* ��ջ������� */
};
typedef struct SNode *Stack;
Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}
 
bool IsFull( Stack S )
{
    return (S->Top == S->MaxSize-1);
}
 
bool Push( Stack S, ElementType X )
{
    if ( IsFull(S) ) {
        printf("��ջ��");
        return false;
    }
    else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}
 
bool IsEmpty( Stack S )
{
    return (S->Top == -1);
}
 
ElementType Pop( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("��ջ��");
        return ERROR; /* ERROR��ElementType������ֵ����־���� */
    }
    else 
        return ( S->Data[(S->Top)--] );
}

//ջ������ʵ�ּ�����
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;
 
Stack CreateStack( ) 
{ /* ����һ����ջ��ͷ��㣬���ظý��ָ�� */
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}
 
bool IsEmpty ( Stack S )
{ /* �ж϶�ջS�Ƿ�Ϊ�գ����Ƿ���true�����򷵻�false */
    return ( S->Next == NULL );
}
 
bool Push( Stack S, ElementType X )
{ /* ��Ԫ��Xѹ���ջS */
    PtrToSNode TmpCell;
    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}
 
ElementType Pop( Stack S )  
{ /* ɾ�������ض�ջS��ջ��Ԫ�� */
    PtrToSNode FirstCell;
    ElementType TopElem;
    if( IsEmpty(S) ) {
        printf("��ջ��"); 
        return ERROR;
    }
    else {
        FirstCell = S->Next; 
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}