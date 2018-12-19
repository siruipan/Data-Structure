typedef struct TreeNode *HuffmanTree;
struct  TreeNode
{
	int Weight;
	HuffmanTree Left,Right;
};

//ÿ�ΰ�Ȩֵ��С�����ö������ϲ�
HuffmanTree Huffman(MinHeap H){
	/* ����H->Size��Ȩֵ�Ѿ�����H->Elements[]->Weight�� */
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

//���帴�Ӷ�ΪO(NlogN)