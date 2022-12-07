#include <stdio.h>
#include <stdlib.h>


typedef struct Vertex{
    int value; 
}Vertex ;

typedef struct Edge{
    Vertex* Head; 
    Vertex* Tail; 
}Edge; 

typedef struct Graph{
    int countVer; 
    int countEdge;
    Vertex * Verts;
    Edge* Edges; 
}Graph; 



Vertex* initVert(int value){
    Vertex * pn = malloc(sizeof(Vertex));
    pn->value = value; 
    return pn; 
}

Edge * initEdge(Vertex* tail, Vertex* head ){
    Edge* pn = malloc(sizeof(Edge));
    pn->Head = head;
    pn->Tail = tail; 
    return pn; 
}

Graph* insertVert(Graph* graph, int value){
    Vertex pn = *initVert(value);
    if(graph->Verts == 0){
        graph->Verts = malloc(sizeof(Vertex));
        graph->countVer++;
        
    }else{
        graph->Verts = realloc(graph->Verts, sizeof(Vertex) * ++graph->countVer);
    }

    graph->Verts[graph->countVer-1] = pn;
    return graph;
}

Graph* insertEdge(Graph* graph, Vertex* tail, Vertex* head){
    Edge edge = *initEdge(tail, head);
    if(!graph->countEdge){
        graph->Edges=malloc(sizeof(Edge));
        graph->countEdge++;
    }else{
        graph->Edges=realloc(graph->Edges, sizeof(Edge)* ++graph->countEdge);
    }
    graph ->Edges[graph->countEdge-1]=edge;
    return graph; 
}



int** initMatrix(Graph* graph){
    int n = graph->countVer;
    int** matrix = calloc(n, sizeof(int*));
    for(int i = 0; i<n; i++){
        matrix[i] = calloc(n, sizeof(int));
        }
        for(int i =0; i<graph->countEdge; i++){
            Edge e = graph-> Edges[i];
            matrix[e.Tail->value][e.Head->value]=1;
        }
        return matrix;

}

Vertex* Mothvex(Graph* graph, int* moth ){
    int size = graph->countVer;
    Vertex* moths = malloc(sizeof(Vertex));
    int** edgeMatrix = initMatrix(graph);
    for(int j = 0; j<size; j++){
        for(int i = 0; i<size; i++){
            if(edgeMatrix[i][j]){
                break;
            }
            if(i == size -1){
                moths[*moth] = graph->Verts[j];
                *moth+=1;
            }
        }
    }
    return moths; 
}

Graph* initGraph(){
    Graph* graph = malloc(sizeof(Graph));
    graph->countVer=0;
    graph->countEdge=0;
    for(int i=0; i<=6; i++){
        insertVert(graph, i);
    }
    insertEdge(graph,&graph->Verts[5], &graph->Verts[2]);
    insertEdge(graph,&graph->Verts[5], &graph->Verts[6]);
    insertEdge(graph,&graph->Verts[6], &graph->Verts[4]);
    insertEdge(graph,&graph->Verts[6], &graph->Verts[0]);
    insertEdge(graph,&graph->Verts[4], &graph->Verts[1]);
    insertEdge(graph,&graph->Verts[1], &graph->Verts[3]);
    insertEdge(graph,&graph->Verts[0], &graph->Verts[2]);
    insertEdge(graph,&graph->Verts[0], &graph->Verts[1]);

    return graph; 
}

int main(void){
    Graph* graph = initGraph();
    
    //printf("\n%d\n",);



    int* moths = malloc(sizeof(int));
    *moths=0;
    Vertex* mothVs = Mothvex(graph, moths);
    //printf("%d", *moths);
    if(moths!=0)
    printf("\n %d is the mother vertex\n",mothVs[0].value);
    
    if(moths==0){
        printf("No mother vertexes");
    }
}
