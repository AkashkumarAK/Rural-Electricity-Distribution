#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define INFINITY 9999
#define MAX 10

struct krush
{
    int x;
    int y;
    int wt;
};
int min=0;

typedef struct krush node;
node arr[8];

 void mergeSort(node arr[], int l,int r ) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr,l,m,r);}}

void merge(node arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  node L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;


  while (i < n1 && j < n2) {
    if (L[i].wt <= M[j].wt)
        {

      arr[k] = L[i];
      i++;
    } else {

      arr[k] = M[j];
      j++;
    }
    k++;
  }


  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;

  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;

  }

}




int kruskal( )
{
    int n,i,j,u,v,parent[8]={0};

printf("---------------------------------------*Getting The random values*------------------------------------\n");
    for (int i=1; i<=8; i++)
    {

        arr[i].wt = 1 + rand() % 20;
    }
    printf("\n");


         mergeSort(arr,0,7);
         printf("--------------------------------The weightage with particular edges are: \n---------------------");
    printf("\nw\t s\t e\t\n");
    for(int i=1;i<=8;i++)
    printf("%d\t %d\t %d\n",arr[i].wt,arr[i].x,arr[i].y);
        printf("------------------Minimum spaning tree for distances over power source to different poles---------\n");
            for (int i = 1; i <=8; i++)
              {
                 u = find(arr[i].x,parent);
                 v = find(arr[i].y,parent);
                 if (uni(u, v,parent))
                 {
                    printf("\n pole no %d and pole no %d with  distance is %d\n", arr[i].x, arr[i].y, arr[i].wt);
                    min += arr[i].wt;
                  }
             }
                 printf(" Sum of distances in minimum spaning tree is :%d\n", min);
                 printf("\n------------------------------------------------------------------------------------------------------------\n");
            return min;
}

int kruskal2( )
{
    int n,i,j,u,v,parent[8]={0};
 printf("--------------------------------------*Getting the random values*-----------------------------------------------------\n");
    for (int i=1; i<=8; i++)
    {

        arr[i].wt = 1 + rand() % 20;

    }
    printf("\n");


         mergeSort(arr,0,8);
         printf("The weightage with particular edges are: \n");
         printf("\nw\t s\t e\t\n");
    for(int i=1;i<=8;i++)
    printf("%d\t %d\t %d\n",arr[i].wt,arr[i].x,arr[i].y);
        printf("----------------------------Minimum spanning tree for distances from the particular pole to different houses are :-----------------\n");

            for (int i = 1; i <=8; i++)
              {
                 u = find(arr[i].x,parent);
                 v = find(arr[i].y,parent);

                 if (uni(u, v,parent))
                 {
                    printf("\n  House no %d and House no %d  distance is %d\n", arr[i].x, arr[i].y, arr[i].wt);
                    min += arr[i].wt;
                  }
             }
                 printf(" \nSum of distances in minimum spanning tree is :%d\n", min);
                 printf("\n----------------------------------------------------------------------------------------------------------------------\n");
            return min;
}



int find(int i,int parent[10])
{
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j,int parent[10])
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
int mini(int d[20],int visited [20])
{
    int min=1000,ind,i;
    for(i=1;i<6;i++)
    {
        if(visited[i]==0 &&d[i]<min)
        {
            min=d[i];
            ind=i;
        }
    }
    return ind;
}
void Dijkstra(int Graph[MAX][MAX]) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < 6; i++)
    for (j = 0; j < 6; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < 6; i++) {
    distance[i] = cost[0][i];
    //pred[i] = start;
    visited[i] = 0;
  }

  distance[0] = 0;
  visited[0] = 1;
  count = 1;

  while (count < 5) {
    mindistance = INFINITY;

    for (i = 0; i < 6; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < 6; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
         // pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < 6; i++)
    if (i != 0) {
      printf("\nDistance from pole  to House no %d is: %d", i, distance[i]);
    }
    printf("\n");
}



int main()
{
    float pw,gr,po,ho,o,g,u;
    float p2,p3;
     pw=560000.0000;
    p3=0.2*pw;
    p2=pw-p3;
    srand(time(NULL));
    int st[]={1,2,3,4,5,2,3,4};
    int en[]={6,3,4,5,6,6,6,6};

    int i,j,Graph[MAX][MAX];
        o=p3/5;
        g=o/5;
     int aa,bb,cc,dd,ee,ff;
    for(i=1;i<=8;i++)
    {
        arr[i].x=st[i-1];
        arr[i].y=en[i-1];
    }

       printf("-----------------------------------------------------------The power source to grid to pole system-------------------------------------------\n");
       aa=kruskal();
       int st1[]={1,1,2,3,4,5,2,3};
    int en1[]={2,6,3,4,5,6,6,6};
       for(i=1;i<=8;i++)
       {
         arr[i].x=st1[i-1];
         arr[i].y=en1[i-1];
       }

       printf("\n---------------------------------------1st pole to houses--------------------------------------------\n");
       bb=kruskal2();

       printf("\n---------------------------------------2nd pole to houses--------------------------------------------\n");
       cc=kruskal2();
       printf("-----------------------------------------3rd pole to houses---------------------------------------------\n");
       dd=kruskal2();
       printf("-----------------------------------------4th pole to houses---------------------------------------------\n");
       ee=kruskal2();
       printf("-----------------------------------------5th pole to houses---------------------------------------------\n");
       ff=kruskal2();


// 1st city
 Graph[0][0] = 0;
  Graph[0][1] = 3;
  Graph[0][2] = 0;
  Graph[0][3] = 0;
  Graph[0][4] = 0;
  Graph[0][5] = 4;


  Graph[1][0] = 3;
  Graph[1][1] = 0;
  Graph[1][2] = 5;
  Graph[1][3] = 0;
  Graph[1][4] = 0;
  Graph[1][5] = 9;


  Graph[2][0] = 0;
  Graph[2][1] = 5;
  Graph[2][2] = 0;
  Graph[2][3] = 6;
  Graph[2][4] = 0;
  Graph[2][5] = 10;


  Graph[3][0] = 0;
  Graph[3][1] = 0;
  Graph[3][2] = 6;
  Graph[3][3] = 0;
  Graph[3][4] = 7;
  Graph[3][5] = 0;


  Graph[4][0] = 0;
  Graph[4][1] = 0;
  Graph[4][2] = 0;
  Graph[4][3] = 7;
  Graph[4][4] = 0;
  Graph[4][5] = 8;


  Graph[5][0] = 4;
  Graph[5][1] = 9;
  Graph[5][2] = 10;
  Graph[5][3] = 0;
  Graph[5][4] = 8;
  Graph[5][5] = 0;
printf("\n----------------------------------------------------Finding shortest path of 1st pole-------------------------------------\n");
Dijkstra(Graph);
// 2nd city
Graph[0][5]=16;
Graph[5][0]=16;

Graph[3][4]=11;
Graph[4][3]=11;

Graph[2][5]=17;
Graph[5][2]=17;
printf("\n----------------------------------------------------Finding shortest path of 2nd pole-------------------------------------\n");
Dijkstra(Graph);
//3rd pole

Graph[1][6]=14;
Graph[6][1]=14;
printf("\n----------------------------------------------------Finding shortest path of 3rd pole-------------------------------------\n");
Dijkstra(Graph);

Graph[0][1]=13;
Graph[1][0]=13;
printf("\n----------------------------------------------------Finding shortest path of 4th pole-------------------------------------\n");
Dijkstra(Graph);

Graph[0][1]=15;
Graph[1][0]=15;

Graph[4][5]=16;
Graph[5][4]=16;

Graph[0][5]=19;
Graph[5][0]=19;
printf("\n----------------------------------------------------Finding shortest path of 5th pole-------------------------------------\n");
Dijkstra(Graph);
printf("\n---------------------------------------------------------------------------------------------------------------------------\n");

printf("\n-----------------------------------------------------------MINIMUM COST OF IMPLEMENTATION----------------------------------------------\n");

printf("\nthe total cost of implementation of the grid system = %d\n",aa*10);
printf("the total cost of implementation of the wires from 1st pole to different houses = %d\n",bb*10);
printf("the total cost of implementation of the wires from 2nd pole to different houses = %d\n",cc*10);
printf("the total cost of implementation of the wires from 3rd pole to different houses = %d\n",dd*10);
printf("the total cost of implementation of the wires from 4th pole to different houses = %d\n",ee*10);
printf("the total cost of implementation of the wires from 5th pole to different houses = %d\n",ff*10);
printf("\nThe total cost of implementing the plan is %d \n",(aa+bb+cc+dd+ee+ff)*10);

printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");


printf("\n-----------------------------------------------------------POWER DISTRIBUTION----------------------------------------------\n");
printf("THE TOTAL POWER GENERATED BY POWERHOUSE IS %.2f watts\n2-PHASE SUPPLY--%.2f watts\n3 PHASE SUPPLY--%.2f watts\n",pw,p2,p3);
printf("The POWER TO EACH POLE HAVING 2 PHASE SUPPLY IS %.2f watts\n",o);
printf("The POWER TO EACH HOUSE HAVING 2 PHASE SUPPLY IS %.2f watt\n",g);
printf("The POWER TO EACH INDUSTRY HAVING 3 PHASE SUPPLY IS %.2f watt\n",p3);




printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");









        }


