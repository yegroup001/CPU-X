#include<stdio.h>
#include<math.h>
#include"omp.h"
#include<stdlib.h>

double parallel(int thread_num);
void end(double diff,int thread_num);

int main()
{
    int m=0,thread_num;
    double diff1,diff2;
    char bool0;
    printf("Please enter the threads number you want to use:");
    scanf("%d",&thread_num);
    //printf("Whether you want to test the single thread performance:(y/n) ");
    //scanf("%c\n",&bool0);
    printf("\nWork start\nThe process may take a few minutes,please wait\n\n");
    /*if(bool0=="y" || bool0=="Y")
    {
        diff1=parallel(thread_num);
        diff2=parallel(1);
        end(diff1,thread_num);
        printf(" %.2f 1thread",1000000.0/diff2);
        printf("\nMulti-threaded multiplier:%.2f",diff2/diff1);
    }
    else*/
    {
        diff1=parallel(thread_num);
        end(diff1,thread_num);
    }
    
    system("pause");
}

double parallel(int thread_num)
{
    double x;
    omp_set_num_threads(thread_num);
    double start = omp_get_wtime( );
    #pragma omp parallel for
    for(int j=0;j<100000;j++)
    {
        #pragma omp parallel for
        for(int i=0;i<100000;i++)
        {
            x=(1-sin(3.1415926535*sqrt(i*i+1)));
        }
    }
    double end = omp_get_wtime( );
    double diff=end-start;
    return diff;
}

void end(double diff,int thread_num)
{
    printf("Work Done\n\n");
    printf("Wall time(Multithreads)is:%lfs\n",diff);

    printf("Your benchmark score:%.2f (%d threads)\n",1000000.0/diff,thread_num);
}
