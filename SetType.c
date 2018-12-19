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
}  //如果X1,X2的父节点相同，但集合深度很大，算法效率低，有没有更高效的算法？edit by SiruiPan

//路径压缩方法，使得并查树更矮
#define MAXN 1000
typedef int Elementype;
typedef int SetName;
typedef Elementype SetType[MAXN];

void Union(SetType S,SetName Root1,SetName Root2){
	if(S[Root1]<S[Root2]){  /* 如果集合2比较大(S[root]=-7代表7个元素) */
		S[Root2]+=S[Root1];
		S[Root1]=Root2;
	}
	else{
		S[Root1] += S[Root2];     /* 集合2并入集合1  */
        S[Root2] = Root1;
	}
}

SetName Find( SetType S, ElementType X )
{  /* 默认集合元素全部初始化为-1 */
    if ( S[X] < 0 ) /* 找到集合的根 */
        return X;
    else
        return S[X] = Find( S, S[X] ); /* 路径压缩 */
}
