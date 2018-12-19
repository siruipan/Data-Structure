//********���Ա��˳��洢*********
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};
 
/* ��ʼ�� */
List MakeEmpty()
{
    List L; 
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}
 
/* ���� */
#define ERROR -1
 
Position Find( List L, ElementType X )
{
    Position i = 0;
 
    while( i <= L->Last && L->Data[i]!= X )
        i++;
    if ( i > L->Last )  return ERROR; /* ���û�ҵ������ش�����Ϣ */
    else  return i;  /* �ҵ��󷵻ص��Ǵ洢λ�� */
}
 
/* ���� */
/*ע��:�ڲ���λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P�Ǵ洢�±�λ�ã���0��ʼ�������߲�1*/
bool Insert( List L, ElementType X, Position P ) 
{ /* ��L��ָ��λ��Pǰ����һ����Ԫ��X */
    Position i;
 
    if ( L->Last == MAXSIZE-1) {
        /* ��ռ����������ܲ��� */
        printf("����"); 
        return false; 
    }  
    if ( P<0 || P>L->Last+1 ) { /* ������λ�õĺϷ��� */
        printf("λ�ò��Ϸ�");
        return false; 
    } 
    for( i=L->Last; i>=P; i-- )
        L->Data[i+1] = L->Data[i]; /* ��λ��P���Ժ��Ԫ��˳������ƶ� */
    L->Data[P] = X;  /* ��Ԫ�ز��� */
    L->Last++;       /* Last��ָ�����Ԫ�� */
    return true; 
} 
 
/* ɾ�� */
/*ע��:��ɾ��λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P�Ǵ洢�±�λ�ã���0��ʼ�������߲�1*/
bool Delete( List L, Position P )
{ /* ��L��ɾ��ָ��λ��P��Ԫ�� */
    Position i;
 
    if( P<0 || P>L->Last ) { /* ���ձ�ɾ��λ�õĺϷ��� */
        printf("λ��%d������Ԫ��", P ); 
        return false; 
    }
    for( i=P+1; i<=L->Last; i++ )
        L->Data[i-1] = L->Data[i]; /* ��λ��P+1���Ժ��Ԫ��˳����ǰ�ƶ� */
    L->Last--; /* Last��ָ�����Ԫ�� */
    return true;   
}

//********���Ա����ʽ�洢*******
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
 
/* ���� */
#define ERROR NULL

List MakeEmpty(){
    List p;
    p=(List)malloc(sizeof(struct LNode));
    p->Next=NULL;
    return p;
}
 
Position Find( List L, ElementType X )
{
    Position p = L; /* pָ��L�ĵ�1����� */
 
    while ( p && p->Data!=X )
        p = p->Next;
 
    /* ������������ return p; �滻 */
    if ( p )
        return p;
    else
        return ERROR;
}
 
/* ��ͷ���Ĳ��� */
/*ע��:�ڲ���λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P��������ָ�룬��P֮ǰ�����½�� */
bool Insert( List L, ElementType X, Position P )
{ /* ����Ĭ��L��ͷ��� */
    Position tmp, pre;
    /* ����P��ǰһ����� */        
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next ) ;            
    if ( pre==NULL ) { /* P��ָ�Ľ�㲻��L�� */
        printf("����λ�ò�������\n");
        return false;
    }
    else { /* �ҵ���P��ǰһ�����pre */
        /* ��Pǰ�����½�� */
        tmp = (Position)malloc(sizeof(struct LNode)); /* ���롢��װ��� */
        tmp->Data = X; 
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
}
 
/* ��ͷ����ɾ�� */
/*ע��:��ɾ��λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P����ɾ�����ָ�� */
bool Delete( List L, Position P )
{ /* ����Ĭ��L��ͷ��� */
    Position tmp, pre;
 
    /* ����P��ǰһ����� */        
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next ) ;            
    if ( pre==NULL || P==NULL) { /* P��ָ�Ľ�㲻��L�� */
        printf("ɾ��λ�ò�������\n");
        return false;
    }
    else { /* �ҵ���P��ǰһ�����pre */
        /* ��Pλ�õĽ��ɾ�� */
        pre->Next = P->Next;
        free(P);
        return true;
    }
}