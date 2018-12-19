typedef struct{
	Elementype Data;
	int Parent;
}SetType;

int Find(SetType S[],Elementype X){
	int i;
	for(i=0;i<MaxSize&&S[i].Data!=X;i++);
	if(i>=MaxSize) return -1;
	for(;S[i].Parent>=0;i=S[i].Parent);
	return i;
}

void Union(SetType S[],Elementype X1,Elementype X2){
	int Root1,Root2;
	Root1=Find(S,X1);
	Root2=Find(S,X2);
	if(Root1!=Root2) S[Root2].Parent=Root1;
}  //���X1,X2�ĸ��ڵ���ͬ����������Ⱥܴ��㷨Ч�ʵͣ���û�и���Ч���㷨��edit by SiruiPan

//·��ѹ��������ʹ�ò���������
#define MAXN 1000
typedef int Elementype;
typedef int SetName;
typedef Elementype SetType[MAXN];

void Union(SetType S,SetName Root1,SetName Root2){
	if(S[Root1]<S[Root2]){  /* �������2�Ƚϴ�(S[root]=-7����7��Ԫ��) */
		S[Root2]+=S[Root1];
		S[Root1]=Root2;
	}
	else{
		S[Root1] += S[Root2];     /* ����2���뼯��1  */
        S[Root2] = Root1;
	}
}

SetName Find( SetType S, ElementType X )
{  /* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 */
    if ( S[X] < 0 ) /* �ҵ����ϵĸ� */
        return X;
    else
        return S[X] = Find( S, S[X] ); /* ·��ѹ�� */
}
