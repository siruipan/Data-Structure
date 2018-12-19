typedef struct TNode *Position;
typedef Position BinTree; /* ���������� */
struct TNode{ /* ����㶨�� */
    ElementType Data; /* ������� */
    BinTree Left;     /* ָ�������� */
    BinTree Right;    /* ָ�������� */
};//��ʽ�洢

void InorderTraversal( BinTree BT )
{
    if( BT ) {
        InorderTraversal( BT->Left );
        printf("%d ", BT->Data); /* ��������Ϊ���� */
        InorderTraversal( BT->Right );
    }
}
 
void PreorderTraversal( BinTree BT )
{
    if( BT ) {
        printf("%d ", BT->Data );
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}
 
void PostorderTraversal( BinTree BT )
{
    if( BT ) {
        PostorderTraversal( BT->Left );
        PostorderTraversal( BT->Right );
        printf("%d ", BT->Data);
    }
}
 
void LevelorderTraversal ( BinTree BT )
{ 
    Queue Q;
    BinTree T;
    if ( !BT ) return; /* ���ǿ�����ֱ�ӷ��� */    
    Q = CreatQueue(); /* �����ն���Q */
    AddQ( Q, BT );
    while ( !IsEmpty(Q) ) {
        T = DeleteQ( Q );
        printf("%d ", T->Data); /* ����ȡ�����еĽ�� */
        if ( T->Left )   AddQ( Q, T->Left );
        if ( T->Right )  AddQ( Q, T->Right );
    }
}

void InOrderTraversal( BinTree BT )
{//��������ķǵݹ�ʵ��
    BinTree T=BT;
    Stack S = CreatStack( MaxSize ); /*��������ʼ����ջS*/
    while( T || !IsEmpty(S) ){
        while(T){ /*һֱ���󲢽���;���ѹ���ջ*/
            Push(S,T);
            T = T->Left;
        }
        if(!IsEmpty(S)){
            T = Pop(S); /*��㵯����ջ*/
            printf(��%5d��, T->Data); /*�����ʣ���ӡ���*/
            T = T->Right; /*ת��������*/
        }
    }
}

int PostOrderGetHeight( BinTree BT )
{//��������߶�
    int HL, HR, MaxH;
    if( BT ) {
        HL = PostOrderGetHeight(BT->Left); /*�������������*/
        HR = PostOrderGetHeight(BT->Right); /*�������������*/
        MaxH = ��HL > HR��? HL : HR; /*ȡ���������ϴ�����*/
        return ( MaxH + 1 ); /*�����������*/
    }
    else return 0; /* �������Ϊ0 */
}

void PreOrderPrintLeaves( BinTree BT )
{//����������е�Ҷ�ӽ��
    if( BT ) {
        if ( !BT-Left && !BT->Right )
            printf(��%d��, BT->Data );
        PreOrderPrintLeaves ( BT->Left );
        PreOrderPrintLeaves ( BT->Right );
    }
}