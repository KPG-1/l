#include<stdio.h>
struct performance_parameters
{
    int rt;
    int ct;
    int tt;
    int wt;
};
//function to read inputs
void readInputs(int n,int *bsum,int arr[][5])
{
    for(int i=0;i<n;i++)
    {
		printf("enter arrival time:");
        scanf("%d",&arr[i][1]);
        printf("enter burst time:");
        scanf("%d",&arr[i][0]);
        arr[i][2]=1;
        arr[i][3]=0;
        printf("enter priority:");
        scanf("%d",&arr[i][4]);
        *bsum=*bsum+arr[i][0];
    }
}
//function to calculate execution sequence and perfoemance parameteres of fcfs
void fcfs(int n,int arr[][5],struct performance_parameters pp[])
{
    printf("FCFS\n");
    int first,small,l=0,systime=0,k=0;
    first=0;//variable used to refer the process, which is to be executed first in each iteration in the for loop
    for(int i=0;i<n;++i)
    {
        small=100;//variable used to compare the arrival time of processes
        for(int j=0;j<n;++j)
        {
            if ((arr[j][2] != 0)&&(arr[j][1]<=systime))
            {
                if(arr[j][1]<small)
                {
                    small=arr[j][1];
                    first=j;
                }
                l=1;
            }
        }
        if(l==1)
        {
            if(k==0)
            {
                k=1;
                systime=arr[first][1];
            }
            arr[first][2]=0;
            //printf("executing process %d\n",(first+1));
            pp[first].rt=systime-arr[first][1];
            pp[first].ct=systime+arr[first][0];
            pp[first].tt=pp[first].ct-arr[first][1];
            pp[first].wt=systime-arr[first][1];
            systime=systime+arr[first][0];
            l=0;
        }
        else
        {
            systime=systime+1;
            i--;
        }
    }
}
//function to calculate execution sequence and perfoemance parameteres of sjf
void sjf(int n,int arr[][5],struct performance_parameters pp[])
{
    printf("sjf\n");
	int first,small,l=0,systime=0,k=0;
    first=0;//variable used to refer the process, which is to be executed first in each iteration in thefor loop
    for(int i=0;i<n;++i)
    {
        small=100;//variable used to compare the BURST time of processes
        for(int j=0;j<n;++j)
        {
            if ((arr[j][2] != 0)&&(arr[j][1]<=systime))
            {
                if(arr[j][0]<small)
                {
                    small=arr[j][0];
                    first=j;
                }
                l=1;
            }
        }
        if(l==1)
        {
            if(k==0)
            {
                k=1;
                systime=arr[first][1];
            }
            arr[first][2]=0;
            pp[first].rt=systime-arr[first][1];
            pp[first].ct=systime+arr[first][0];
            pp[first].tt=pp[first].ct-arr[first][1];
            pp[first].wt=systime-arr[first][1];
            systime=systime+arr[first][0];
            l=0;
        }
        else
        {
            systime=systime+1;
            i--;
        }
	}
}
//function to calculate execution sequence and perfoemance parameteres of priority
void priority(int n,int arr[][5],struct performance_parameters pp[])
{
    printf("PRIORITY\n");
    int first,small,l=0,systime=0,k=0;
    first=0;//variable used to refer the process, which is to be executed first in each iteration in thefor loop
    for(int i=0;i<n;++i)
    {
        small=100;//variable used to compare the priority of processes
        for(int j=0;j<n;++j)
        {
            if ((arr[j][2] != 0)&&(arr[j][1]<=systime))
            {
                if(arr[j][4]<small)
                {
                    small=arr[j][4];
                    first=j;
                }
                l=1;
            }
        }
        if(l==1)
        {
            if(k==0)
            {
                k=1;
                systime=arr[first][1];
            }
            arr[first][2]=0;
            //printf("executing process %d\n",(first+1));
            pp[first].rt=systime-arr[first][1];
            pp[first].ct=systime+arr[first][0];
            pp[first].tt=pp[first].ct-arr[first][1];
            pp[first].wt=systime-arr[first][1];
            systime=systime+arr[first][0];
            l=0;
        }
        else
        {
            systime=systime+1;
            i--;
        }
    }
}
//function to calculate execution sequence and perfoemance parameteresof round robin
void rr(int n,int bsum,int arr[][5],struct performance_parameters pp[])
{
    printf("ROUND ROBIN\n");
    int first,small,l=0,systime=0,k=0;
    first=0;
    for(int i=0;i<bsum;++i)
    {
        small=100;
        for(int j=0;j<n;++j)
        {
            if ((arr[j][2] != 0)&&(arr[j][1]<=systime))
            {
                if(arr[j][3]<small)
                {
                    small=arr[j][3];
                    first=j;
                }
                l=1;
            }
        }
        if(l==1)
        {
            if(k==0)
            {
                k=1;
                systime=arr[first][1];
            }
            //printf("executing process %d\n",(first+1));
            arr[first][3]=arr[first][3]+1;
            arr[first][0]=arr[first][0]-1;
            if(arr[first][0]<=0)
            {
                arr[first][2]=0;
                if(arr[first][0]<0)
                {
                    pp[first].ct=systime;
                }
                else
                {
                    pp[first].ct=systime+1;
                }
                pp[first].tt=pp[first].ct-arr[first][1];
                pp[first].wt=pp[first].tt-arr[first][3];
            }
            if(arr[first][3]==1)
            {
                pp[first].rt=systime-arr[first][1];
            }
            systime=systime+1;
            l=0;
        }
        else
        {
            systime=systime+1;
            i--;
        }
    }
}
//function to print the result
void printResult(int n,struct performance_parameters pp[])
{
    printf("\n");
	float rtsum=0,ctsum=0,ttsum=0,wtsum=0;
	printf("PID  RESPONCE TIME  COMPLETION TIME  TURNAROUND TIME  WAITING TIME\n");
    for(int i=0;i<n;++i)
    {
        printf("P%d      %d              %d               %d               %d",i+1,pp[i].rt,pp[i].ct,pp[i].tt,pp[i].wt);
        printf("\n");
        rtsum=rtsum+pp[i].rt;
        ctsum=ctsum+pp[i].ct;
        ttsum=ttsum+pp[i].tt;
        wtsum=wtsum+pp[i].wt;
    }
    printf("\nAVERAGE RESPONCE TIME     : %f\n",(rtsum/n));
    printf("AVERAGE COMPLETION TIME   : %f\n",(ctsum/n));
    printf("AVERAGE TURNAROUND TIME   : %f\n",(ttsum/n));
    printf("AVERAGE WAITING TIME      : %f\n",(wtsum/n));
    printf("\n");
}
void main()
{
    int n;
    int bsum=0;//sum of burst times of all processes
    printf("enter the number of processes:");
    scanf("%d",&n);
    int arr[n][5];
    //arr[x][0] used to store burst time
    //arr[x][1] used to store arrival time
    //arr[x][2] initially set to 1 for all processes and set to 0 if the process is choosen to execute
    //arr[x][3] initially set to 0, used to count the number of times CPU allocated for the process
    //arr[x][4] used to store priority
    readInputs(n,&bsum,arr);
    struct performance_parameters ppfcfs[n];
    fcfs(n,arr,ppfcfs);
    printResult(n,ppfcfs);
    for(int a=0;a<n;a++){
        arr[a][2]=1;
	}
    struct performance_parameters ppsjf[n];
    sjf(n,arr,ppsjf);
    printResult(n,ppsjf);
    for(int a=0;a<n;a++){
        arr[a][2]=1;
	}
    struct performance_parameters pppriority[n];
    priority(n,arr,pppriority);
    printResult(n,pppriority);
    for(int a=0;a<n;a++){
        arr[a][2]=1;
	}
    struct performance_parameters pprr[n];
    rr(n,bsum,arr,pprr);
    printResult(n,pprr);
}