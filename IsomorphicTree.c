#include<stdio.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TNode
{
	ElementType Data;
	Tree Left;
	Tree Right;
}BT1[MaxTree],BT2[MaxTree];

Tree CreatTree(struct TNode BT[]);
int Isomorphic(Tree R1,Tree R2);

int main(int argc, char const *argv[])
{
	Tree R1,R2;
	R1=CreatTree(BT1);
	R2=CreatTree(BT2);
	if(Isomorphic(R1,R2)) printf("Yes");
	else printf("No");
	return 0;
}

Tree CreatTree(struct TNode BT[]){
	int i,N;
	int check[N];
	Tree Root;
	Tree cl,cr;
	scanf("%d\n",&N);
	if(N){
	  for(i=0;i<N;check[i]=0,i++)
		for(i=0;i<N;i++){
			scanf("%c %c %c\n",&BT[i].Data,&cl,&cr);
			if(cl!='-'){
				BT[i].Left=cl-'0';
				check[BT[i].Left]=1;
			}
			else BT[i].Left=Null;
			if(cr!='-'){
				BT[i].Right=cr-'0';
				check[BT[i].Right]=1;
			}
			else BT[i].Right=Null;
		}
		for (i=0;i<N;i++)
		{
			if(!check[i]) break;
		}
		Root=i;
	}
	return Root;
}

int Isomorphic(Tree R1,Tree R2){
	if(R1==Null&&R2==Null) return 1;
	if((R1==Null&&R2!=Null)||(R1!=Null&&R2==Null))
		return 0;
	if(BT1[R1].Data!=BT2[R2].Data) return 0;
	if(BT1[R1].Left==Null&&BT2[R2].Right==Null)
		return Isomorphic(BT1[R1].Right,BT2[R2].Right);
	if(((BT1[R1].Left!=Null)&&(BT2[R2].Left!=Null))&&((BT1[BT1[R1].Left].Data)==(BT2[BT2[R2].Left].Data)))
		return (Isomorphic(BT1[R1].Left,BT2[R2].Left)&&Isomorphic(BT1[R1].Right,BT2[R2].Right));
	else 
	  return(Isomorphic(BT1[R1].Left,BT2[R2].Right)&&Isomorphic(BT1[R1].Right,BT2[R2].Left));
}