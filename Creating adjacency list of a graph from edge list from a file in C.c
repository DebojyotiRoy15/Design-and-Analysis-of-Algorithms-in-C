#include<stdio.h>
#include<stdlib.h>

FILE *fp;

struct node{
  int v_weight;
  int dest;
  int deg;
  struct node *next;
};

int main (void)
{
      struct node *new;
      int vertices, source, dest, weight;
      fp = fopen("adjacencylist.txt", "r");
      if (fp!=NULL)
      {
                fscanf(fp, "%d ", &vertices);  
                struct node *graph = (struct node *)malloc(sizeof(struct node));
                initialise(graph, vertices);
                while(!feof(fp))
                {
                        fscanf(fp, "%d %d %d ", &source, &dest, &weight);
                        new = (struct node *)malloc(sizeof(struct node));
                        new->dest = dest;
                        new->v_weight = weight;
                        new->next = graph[source].next;
                        graph[source].next = new;
                        graph[source].deg++;
                }
        display(graph, vertices);
      }     
      else
      {
                        printf("Error in accessing file!!! \n");
                        exit(0);
      }
      return 0;
}

void initialise(struct node *graph, int n)
{
      int i;
      for(i=0;i<n;i++)
      {
              graph[i].next=NULL;
              graph[i].deg = 0;
      }
}

void display(struct node *graph, int n)
{
    int i;
    struct node *temp;
    for(i=0;i<n;i++)
    {
          temp = graph[i].next;
          printf("Degree of %d is %d \n", i, graph[i].deg);
          while(temp!=NULL)
          {
                printf("The source is %d \n", i);
                printf("The destination is %d \n", temp->dest);
                printf("The weight is %d \n", temp->v_weight);
                printf("\n");
                temp = temp->next;
          }
    }

}
