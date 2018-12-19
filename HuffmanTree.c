typedef struct TreeNode *HuffmanTree;
struct  TreeNode
{
	int Weight;
	HuffmanTree Left,Right;
};

//每次把权值最小的两棵二叉树合并
HuffmanTree Huffman(MinHeap H){
	/* 假设H->Size个权值已经存在H->Elements[]->Weight里 */
	int i;
	HuffmanTree T;
	BuildMinHeap(H);
	for(i=1;i<H->Size;i++){
		T=(HuffmanTree)malloc(sizeof(struct TreeNode));
		T->Left=DeleteMin(H);
		T->Right=DeleteMin(H);
		T->Weight=T->Left->Weight+T->Right->Weight;
		Insert(H,T);
	}
	T=DeleteMin(H);
	return T;
}

//整体复杂度为O(NlogN)