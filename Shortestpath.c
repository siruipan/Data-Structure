/* �ڽӱ�洢 - ��Ȩͼ�ĵ�Դ���·�㷨 */
/* dist[]��path[]ȫ����ʼ��Ϊ-1 */
void Unweighted ( LGraph Graph, int dist[], int path[], Vertex S )
{
    Queue Q;
    Vertex V;
    PtrToAdjVNode W;
     
    Q = CreateQueue( Graph->Nv ); /* �����ն���, MaxSizeΪ�ⲿ����ĳ��� */
    dist[S] = 0; /* ��ʼ��Դ�� */
    AddQ (Q, S);
 
    while( !IsEmpty(Q) ){
        V = DeleteQ(Q);
        for ( W=Graph->G[V].FirstEdge; W; W=W->Next ) /* ��V��ÿ���ڽӵ�W->AdjV */
            if ( dist[W->AdjV]==-1 ) { /* ��W->AdjVδ�����ʹ� */
                dist[W->AdjV] = dist[V]+1; /* W->AdjV��S�ľ������ */
                path[W->AdjV] = V; /* ��V��¼��S��W->AdjV��·���� */
                AddQ(Q, W->AdjV);
            }
    } /* while����*/
}


/* �ڽӾ���洢 - ��Ȩͼ�ĵ�Դ���·�㷨 */
 
Vertex FindMinDist( MGraph Graph, int dist[], int collected[] )
{ /* ����δ����¼������dist��С�� */
    Vertex MinV, V;
    int MinDist = INFINITY;
 
    for (V=0; V<Graph->Nv; V++) {
        if ( collected[V]==false && dist[V]<MinDist) {
            /* ��Vδ����¼����dist[V]��С */
            MinDist = dist[V]; /* ������С���� */
            MinV = V; /* ���¶�Ӧ���� */
        }
    }
    if (MinDist < INFINITY) /* ���ҵ���Сdist */
        return MinV; /* ���ض�Ӧ�Ķ����±� */
    else return ERROR;  /* �������Ķ��㲻���ڣ����ش����� */
}
 
bool Dijkstra( MGraph Graph, int dist[], int p ath[], Vertex S )
{
    int collected[MaxVertexNum];
    Vertex V, W;
 
    /* ��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INFINITY��ʾ */
    for ( V=0; V<Graph->Nv; V++ ) {
        dist[V] = Graph->G[S][V];
        if ( dist[V]<INFINITY )
            path[V] = S;
        else
            path[V] = -1;
        collected[V] = false;
    }
    /* �Ƚ�������뼯�� */
    dist[S] = 0;
    collected[S] = true;
 
    while (1) {
        /* V = δ����¼������dist��С�� */
        V = FindMinDist( Graph, dist, collected );
        if ( V==ERROR ) /* ��������V������ */
            break;      /* �㷨���� */
        collected[V] = true;  /* ��¼V */
        for( W=0; W<Graph->Nv; W++ ) /* ��ͼ�е�ÿ������W */
            /* ��W��V���ڽӵ㲢��δ����¼ */
            if ( collected[W]==false && Graph->G[V][W]<INFINITY ) {
                if ( Graph->G[V][W]<0 ) /* ���и��� */
                    return false; /* ������ȷ��������ش����� */
                /* ����¼Vʹ��dist[W]��С */
                if ( dist[V]+Graph->G[V][W] < dist[W] ) {
                    dist[W] = dist[V]+Graph->G[V][W]; /* ����dist[W] */
                    path[W] = V; /* ����S��W��·�� */
                }
            }
    } /* while����*/
    return true; /* �㷨ִ����ϣ�������ȷ��� */
}


/* �ڽӾ���洢 - ��Դ���·�㷨 */
 
bool Floyd( MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum] )
{
    Vertex i, j, k;
    /* ��ʼ�� */
    for ( i=0; i<Graph->Nv; i++ )
        for( j=0; j<Graph->Nv; j++ ) {
            D[i][j] = Graph->G[i][j];
            path[i][j] = -1;
        }
 
    for( k=0; k<Graph->Nv; k++ )
        for( i=0; i<Graph->Nv; i++ )
            for( j=0; j<Graph->Nv; j++ )
                if( D[i][k] + D[k][j] < D[i][j] ) {
                    D[i][j] = D[i][k] + D[k][j];
                    if ( i==j && D[i][j]<0 ) /* �����ָ�ֵȦ */
                        return false; /* ������ȷ��������ش����� */
                    path[i][j] = k;
                }
    return true; /* �㷨ִ����ϣ�������ȷ��� */
}