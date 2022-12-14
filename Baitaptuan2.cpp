#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex {
   char label;
   bool visited;
};

//khai bao cac bien cho ngan xep (stack)

int stack[MAX]; 
int top = -1; 

//khai bao cac bien lien quan toi do thi (graph)

//khai bao danh sach cac dinh (Vertex)
struct Vertex* lstVertices[MAX];

//Khai bao mot ma tran ke (adjacency matrix)
int adjMatrix[MAX][MAX];

//khai bao mot bien de dem so dinh
int vertexCount = 0;

//cac ham thao tac voi ngan xep

void push(int item) { 
   stack[++top] = item; 
} 

int pop() { 
   return stack[top--]; 
} 

int peek() {
   return stack[top];
}

bool isStackEmpty() {
   return top == -1;
}

//cac ham thao tac tren do thi

//them dinh vao danh sach cac dinh
void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;  
   vertex->visited = false;     
   lstVertices[vertexCount++] = vertex;
}

//them canh vao mang cac canh
void addEdge(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}

//hien thi dinh
void displayVertex(int vertexIndex) {
   printf("%c ",lstVertices[vertexIndex]->label);
}       

//lay dinh chua duyet tu ma tran ke
int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i<vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
         return i;
      }
   }

   return -1;
}

void depthFirstSearch() {
   int i;

   //danh dau nut dau tien (first node) la da duyet (visited)
   lstVertices[0]->visited = true;

   //hien thi dinh
   displayVertex(0);   

   //chen chi muc cua dinh vao trong ngan xep
   push(0);

   while(!isStackEmpty()) {
      //Rut dinh chua duoc duyet tu ngan xep
      int unvisitedVertex = getAdjUnvisitedVertex(peek());

      //khong tim thay dinh lien ke
      if(unvisitedVertex == -1) {
         pop();
      }else {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         push(unvisitedVertex);
      }
   }

   //ngan xep la trong, hoan thanh tim kiem, reset gia tri cua visited            
   for(i = 0;i < vertexCount;i++) {
      lstVertices[i]->visited = false;
   }        
}

int main() {
   int i, j;

   for(i = 0; i<MAX; i++)  { // thiet lap cac gia tri
      for(j = 0; j<MAX; j++) // cua ma tran ke la 0
         adjMatrix[i][j] = 0;
   }

   addVertex('0');   // 0
   addVertex('1');   // 1
   addVertex('2');   // 2
   addVertex('3');   // 3
   addVertex('4');   // 4

   addEdge(0, 1);    // S - A
   addEdge(0, 2);    // S - B
   addEdge(0, 3);    // S - C
   addEdge(1, 4);    // A - D
   addEdge(2, 4);    // B - D
   addEdge(3, 4);    // C - D

   printf("Tim kiem theo chieu sau: ");

   depthFirstSearch(); 

   return 0;}   
