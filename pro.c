#include<stdio.h>

int main()
{
    int BT[10],P_no[10],W_T[10],T_A_T[10];
    int AT[10],P[10],i,j,NOP,tot=0,flag,temp,Avg_W_T,Avg_T_A_T;
    printf("Enter Number of Process:");
    scanf("%d",&NOP);
    printf("\n----------------Enter Burst Time and Priority----------------\n");
    for(i=0;i<NOP;i++)
    {
        printf("\nP[%d]\n",(i+1));
        printf("---Enter Burst Time---:");
        scanf("%d",&BT[i]);
        printf("---Enter Arrival Time---:");
        scanf("%d",&AT[i]);
        printf("---Enter Priority---:");
        scanf("%d",&P[i]);
        P_no[i]=i+1;
    }
    for(i=0;i<NOP;i++)
    {
        flag=i;
        for(j=i+1;j<NOP;j++)
        {
            if(P[j]<P[flag])
            flag=j;
        }
        temp=P[i];
        P[i]=P[flag];
        P[flag]=temp;
        temp=BT[i];
        BT[i]=BT[flag];
        BT[flag]=temp;
        temp=P_no[i];
        P_no[i]=P_no[flag];
        P_no[flag]=temp;
    }
    W_T[0]=0;  
    for(i=1;i<NOP;i++)
    {
        W_T[i]=0;
        for(j=0;j<i;j++)
            W_T[i]+=BT[j];
        tot+=W_T[i];
    }
    Avg_W_T=tot/NOP;  
    tot=0;
    printf("_________________________________________________________________________________________________________________");
    printf("\nProcess     |    ||Burst Time||     |        ||Waiting Time||          |        ||Turn Around Time||          |");
    for(i=0;i<NOP;i++)
    {
        T_A_T[i]=BT[i]+W_T[i];  
        tot+=T_A_T[i];
     printf(" \nProcess- %d  |         %d\t            |      \t   %d                   |\t\t%d                     |",P_no[i],BT[i],W_T[i],T_A_T[i] );
    }
    printf("\n________________________________________________________________________________________________________________\n");
    Avg_T_A_T=tot/NOP;
    printf("*************************************************");
    printf("\n\t  Average Waiting Time= %d",Avg_W_T);
    printf("\n\t  Average Turn Around Time= %d\n",Avg_T_A_T);
    printf("*************************************************\n");
    return 0;
}
