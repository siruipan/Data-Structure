typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode{ /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
};//链式存储

void InorderTraversal( BinTree BT )
{
    if( BT ) {
        InorderTraversal( BT->Left );
        printf("%d ", BT->Data); /* 假设数据为整型 */
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
    if ( !BT ) return; /* 若是空树则直接返回 */    
    Q = CreatQueue(); /* 创建空队列Q */
    AddQ( Q, BT );
    while ( !IsEmpty(Q) ) {
        T = DeleteQ( Q );
        printf("%d ", T->Data); /* 访问取出队列的结点 */
        if ( T->Left )   AddQ( Q, T->Left );
        if ( T->Right )  AddQ( Q, T->Right );
    }
}

void InOrderTraversal( BinTree BT )
{//中序遍历的非递归实现
    BinTree T=BT;
    Stack S = CreatStack( MaxSize ); /*创建并初始化堆栈S*/
    while( T || !IsEmpty(S) ){
        while(T){ /*一直向左并将沿途结点压入堆栈*/
            Push(S,T);
            T = T->Left;
        }
        if(!IsEmpty(S)){
            T = Pop(S); /*结点弹出堆栈*/
            printf(“%5d”, T->Data); /*（访问）打印结点*/
            T = T->Right; /*转向右子树*/
        }
    }
}

int PostOrderGetHeight( BinTree BT )
{//求二叉树高度
    int HL, HR, MaxH;
    if( BT ) {
        HL = PostOrderGetHeight(BT->Left); /*求左子树的深度*/
        HR = PostOrderGetHeight(BT->Right); /*求右子树的深度*/
        MaxH = （HL > HR）? HL : HR; /*取左右子树较大的深度*/
        return ( MaxH + 1 ); /*返回树的深度*/
    }
    else return 0; /* 空树深度为0 */
}

void PreOrderPrintLeaves( BinTree BT )
{//输出二叉树中的叶子结点
    if( BT ) {
        if ( !BT-Left && !BT->Right )
            printf(“%d”, BT->Data );
        PreOrderPrintLeaves ( BT->Left );
        PreOrderPrintLeaves ( BT->Right );
    }
}