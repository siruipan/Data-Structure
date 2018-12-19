/* �ڽӱ�洢��ͼ - DFS */ 
void Visit( Vertex V )
{
    printf("���ڷ��ʶ���%d\n", V);
}
 
/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */
void DFS( LGraph Graph, Vertex V, void (*Visit)(Vertex) )
{   /* ��VΪ��������ڽӱ�洢��ͼGraph����DFS���� */
    PtrToAdjVNode W;
     
    Visit( V ); /* ���ʵ�V������ */
    Visited[V] = true; /* ���V�ѷ��� */
 
    for( W=Graph->G[V].FirstEdge; W; W=W->Next ) /* ��V��ÿ���ڽӵ�W->AdjV */
        if ( !Visited[W->AdjV] )    /* ��W->AdjVδ������ */
            DFS( Graph, W->AdjV, Visit );    /* ��ݹ����֮ */
}

/**************************�ָ���*************************/

/* �ڽӾ���洢��ͼ - BFS */

/* IsEdge(Graph, V, W)���<V, W>�Ƿ�ͼGraph�е�һ���ߣ���W�Ƿ�V���ڽӵ㡣  */
/* �˺�������ͼ�Ĳ�ͬ����Ҫ����ͬ��ʵ�֣��ؼ�ȡ���ڶԲ����ڵıߵı�ʾ������*/
/* �������Ȩͼ, ��������ڵı߱���ʼ��ΪINFINITY, ����ʵ������:         */
bool IsEdge( MGraph Graph, Vertex V, Vertex W )
{
    return Graph->G[V][W]<INFINITY ? true : false;
}
 
/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */
void BFS ( MGraph Graph, Vertex S, void (*Visit)(Vertex) )
{   /* ��SΪ��������ڽӾ���洢��ͼGraph����BFS���� */
    Queue Q;     
    Vertex V, W;
 
    Q = CreateQueue( MaxSize ); /* �����ն���, MaxSizeΪ�ⲿ����ĳ��� */
    /* ���ʶ���S���˴��ɸ��ݾ��������Ҫ��д */
    Visit( S );
    Visited[S] = true; /* ���S�ѷ��� */
    AddQ(Q, S); /* S����� */
     
    while ( !IsEmpty(Q) ) {
        V = DeleteQ(Q);  /* ����V */
        for( W=0; W<Graph->Nv; W++ ) /* ��ͼ�е�ÿ������W */
            /* ��W��V���ڽӵ㲢��δ���ʹ� */
            if ( !Visited[W] && IsEdge(Graph, V, W) ) {
                /* ���ʶ���W */
                Visit( W );
                Visited[W] = true; /* ���W�ѷ��� */
                AddQ(Q, W); /* W����� */
            }
    } /* while����*/
}

/******************�ָ���*****************/
//ͼ����ͨ��
void ListComponents(Graph G){
	for(each V in G)
		if(!visited[V]){
			DFS(V); /*or BFS(V) */
		}
}