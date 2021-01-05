#include<stdio.h>
#include<stdlib.h>
#define Ready 1
#define Waiting 2
#define Processed 3

struct node
{
    int vertex;
    struct node *next;
};

int main()
{
    int i, nodes;
    printf("Masukkan Jumlah Vertex : ");
    scanf("%d", &nodes);
    struct node *Adj[nodes];
    for(i = 0; i < nodes; i++)
        Adj[i] = NULL;
    struct node *new_node, *last;
    int j, n, val;
    for(i = 0; i < nodes; i++)
    {
        last = NULL;
        printf("\nMasukkan Jumlah Tetangga Vertex %d: ", i);
        scanf("%d", &n);
        for(j = 1; j <= n; j++)
        {
            printf("Masukkan Tetangga %d yang ke-%d: ", i, j);
            scanf("%d", &val);
            new_node = (struct node *) malloc(sizeof(struct node));
            new_node -> vertex = val;
            new_node -> next = NULL;
            if (Adj[i] == NULL)
                Adj[i] = new_node;
            else
                last -> next = new_node;
            last = new_node;
        }
    }
    dfs(Adj,nodes);
}

int dfs(struct node*Adj[],int nodes)
{
    struct node *ptr,*top;
    int start,i,status[nodes];
    for(i=0;i<nodes;i++)
        status[i]=Ready;
    printf("\n\nmasukkan vertex awal (0-%d): ",nodes-1);scanf("%d",&start);
    ptr=(struct node *) malloc(sizeof(struct node));
    ptr->vertex=start;
    ptr->next=NULL;
    top=ptr;
    while(top!=NULL)
    {
        struct node *ptr1,*bantu;
        ptr1=top;
        top=top->next;
        printf("%d\n",ptr1->vertex);
        status[ptr1->vertex]=Processed;
        bantu=Adj[ptr1->vertex];
        free(ptr1);
        while(bantu!=NULL)
        {
            if(status[bantu->vertex]==Ready)
            {
                status[bantu->vertex]=Waiting;
                ptr=(struct node *) malloc(sizeof(struct node));
                ptr->vertex=bantu->vertex;
                ptr->next=top;
                top=ptr;
            }
           bantu=bantu->next;
        }
    }
}
