#include <stdio.h>
#include <stdlib.h>

FILE *fp;

void swap(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

struct knap{
    float weight;
    float profit;
    float pw;
    int num;
}

int main()
{
    struct knap list[5];
    int sumwt = 0, n, i,j,m=50;
    float sumpr = 0;
    fp = fopen("fractionalknapsack.c", "r");
    if (fp!=NULL)
    {
           fscanf(fp, "%d ", &n);
           while(!feof(fp))
           {
                for(i=0;i<n;i++)
                {
                        list[i].num = i+1;
                        fscanf(fp, "%f %f ", &list[i].profit, &list[i].weight); 
                }
           }
    }
    else
    {
               printf("Error in opening file!!!! \n");
               exit(0);
    }
    for(i=0;i<n;i++)
            pw[i] = (profit[i]/weight[i]);
    int tempo;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
    {
        if(list[j].pw<list[j+1].pw)
        {
            swap(&list[j].pw, &list[j+1].pw);
            swap(&list[j].profit, &list[j+1].profit);
            swap(&list[j].weight, &list[j+1].weight);
            tempo = list[j].num;
            list[j].num = list[j+1].num;
            list[j+1].num = tempo;
        }
    }
    int max;
    max = m;
    i=0;
    while(sumwt < max)
    {
        if(list[i].weight<m)
        {
            sumpr = sumpr + list[i].profit;
            sumwt = sumwt + list[i].weight;
            m = m - list[i].weight;
            printf("%d Element taken in whole fraction. \n", list[i].num);
        }
        else if(list[i].weight>m)
        {
            sumwt = sumwt + m;
            sumpr = sumpr + (list[i].pw)*m;
            printf("%d Element taken in fraction %f ", list[i].num, (list[i].pw)*m);
        }
        i++;

    }
    printf("The profit is %f: ", sumpr);
    return 0;
}
