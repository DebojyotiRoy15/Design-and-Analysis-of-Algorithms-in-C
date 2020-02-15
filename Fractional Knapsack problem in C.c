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

int main()
{
    float profit[3], weight[3], temp;
    float pw[3];
    int prof, m, wt, rem, sumwt=0,i,j,n;
    float sumpr = 0;
    fp = fopen("fractionalknapsack.c", "r");
    if (fp!=NULL)
    {
           fscanf(fp, "%d ", &n);
           while(!feof(fp))
           {
                for(i=0;i<n;i++)
                {
                        fscanf(fp, "%f %f ", &profit[i], &weight[i]); 
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
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
    {
        if(pw[j]<pw[j+1])
        {
            swap(&pw[j], &pw[j+1]);
            swap(&profit[j], &profit[j+1]);
            swap(&weight[j], &weight[j+1]);
        }
    }
    printf("\n Enter max weight: \n");
    scanf("%d", &m);
    int max;
    max = m;
    i=0;
    while(sumwt < max)
    {
        if(weight[i]<m)
        {
            sumpr = sumpr + profit[i];
            sumwt = sumwt + weight[i];
            m = m - weight[i];
        }
        else if(weight[i]>m)
        {
            sumwt = sumwt + m;
            sumpr = sumpr + pw[i]*m;
        }
        i++;

    }
    printf("The profit is %f: ", sumpr);
    return 0;
}
