#include<iostream>
#include<stdlib.h>
#define MAX 200
using namespace std;
int hn[MAX]={-1};
int n;                    // no. of vertices
int src, dest;               // source & destination nodes
struct node
{
      int data;
      int cost;
      struct node *next;
};
void append(struct node **head, int data, int cost)   //append(&arr[i], j+1, mat[i][j]);
{
       struct node *temp = (struct node*)malloc(sizeof(struct node));
       temp->data = data;
       temp->cost = cost;
       temp->next = NULL;
       if(*head == NULL)
       {
            *head = temp;
       }
       else
       {
            struct node *tmp = *head;
            while(tmp->next != NULL)
                 tmp = tmp->next;//getting last node
            tmp->next = temp;
       }
  }
  int min(int *arr, int size)
  {
       int k = arr[0], l=0;
       for(int i=1; i<size; i++)
       {
            if(arr[i] < k)
            {
                 k = arr[i];
                 l = i;
            }
       }
       return l;
  }
  void a_star(struct node **arr)
  {
       struct node *temp;
       int x=0, y=0, path[n], cost[n];
       cout<<"\n\n";
       cout<<"Optimal Path: \n";
       cout<<"--------------\n";
       cout<<src<<" ";
       while(path[x-1] != dest)
       {
            int i=0, j=0, v[n], fn[n];
            for(temp = *(arr+src-1); temp; temp=temp->next)
            {
                 fn[i++] = temp->cost + hn[temp->data-1];
                 v[j++] = temp->data;
            }
            j = min(fn, i);
            path[x++] = src = v[j];
            cost[y++] = fn[j] - hn[v[j]-1];
       }
       int i=0;
       int cst=0;
       while(i<x)
            cout<<path[i]<<" ", cst+=cost[i++];
       cout<<"\nOptimal Cost: \n";
       cout<<"--------------\n";
       cout<<cst;
       cout<<"\n\n";
  }
  int main()
  {
       cout<<"\n\nEnter no. of vertices: ";
       cin>>n;
       int mat[n][n];
       struct node *arr[n];
       cout<<"\n\nEnter Adjacency Matrix of size ["<<n<<"x"<<n<<"]: \n";
       cout<<"--------------------------------------\n";
       for(int i=0; i<n; i++)
       {
            for(int j=0; j<n; j++)
            {
                 cin>>mat[i][j];
            }
       }
       for(int i=0; i<n; i++)
       {
            arr[i] = NULL;
            for(int j=0; j<n; j++)
            {
                 if(mat[i][j] > 0)
                 {
                      append(&arr[i], j+1, mat[i][j]);
                 }
            }
       }
      /* for(int i=0; i<n; i++)
       {
    	   cout<<arr[i];

       }*/
       cout<<"\n\nEnter values of h(n): ";
       cout<<"\n----------------------";
       for(int i=0; i<n; i++)
            cout<<"\nh(n) of vertex "<<i+1<<" : ", cin>>hn[i];
       label:
       cout<<"\n\nEnter source & destination: ", cout<<"\n----------------------------";
       cout<<"\nEnter source vertex: ", cin>>src;
       cout<<"\nEnter destination vertex: ", cin>>dest;
       if( src > n || dest > n)
       {
            cout<<"\nPlease enter valid nodes !!";
            goto label;
       }
       a_star(arr);
       return 0;
  }


  /*Output:
  bash-4.2$ g++ astar.cpp
bash-4.2$ ./a.out


Enter no. of vertices: 10


Enter Adjacency Matrix of size [10x10]:
--------------------------------------
999 7 20 999 999 17 999 10 999 999
7 999 999 999 9 11 14 999 999 999
20 999 999 999 5 999 999 999 999 999
999 999 999 999 6 999 14 999 18 20
999 9 5 6 999 999 12 999 999 19
17 11 999 999 999 999 999 8 16 999
999 14 999 14 12 999 999 999 999 999
10 999 999 999 999 8 999 999 999 999
999 999 999 18 999 16 999 999 999 15
999 999 999 20 19 999 999 999 15 999


Enter values of h(n):
----------------------
h(n) of vertex 1 : 58

h(n) of vertex 2 : 38

h(n) of vertex 3 : 27

h(n) of vertex 4 : 23

h(n) of vertex 5 : 21

h(n) of vertex 6 : 41

h(n) of vertex 7 : 37

h(n) of vertex 8 : 42

h(n) of vertex 9 : 17

h(n) of vertex 10 : 0


Enter source & destination:
----------------------------
Enter source vertex: 1

Enter destination vertex: 10


Optimal Path:
--------------
1 2 5 10
Optimal Cost:
--------------
35*/
