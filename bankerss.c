#include<stdio.h>
void read(int num1,int num2,int this[num1][num2],int this1[num1][num2]){
	for(int i=0;i<num1;i++){
		for(int j=0;j<num2;j++){
			printf("Enter allocationn of resources %d of process %d:",j+1,i+1);
			scanf("%d",&this[i][j]);
			printf("Enter max of resources %d of process %d:",j+1,i+1);
			scanf("%d",&this1[i][j]);
		}
	}
}
void calneed(int num1,int num2,int this[num1][num2],int this1[num1][num2],int this2[num1][num2]){
	int i,j;
	for(int i=0;i<num1;i++){
		for(int j=0;j<num2;j++){
			this2[i][j]=this1[i][j]-this[i][j];
			//printf("Need:%d",this2[i][j]);
		}
	}			
}
void safe(int num1,int num2,int this[num1][num2],int this1[num2],int this2[num1],int safeseq[num1]){
	//int flag[num1];
	int count=0;
	int i,j,k,a;
	int flag=0;
	/*for(i=0;i<num1;i++){
		flag[i]=0;
		for(j=0;j<num2;j++){
			if(this[i][j]>this1[j]){
				this2[i]=0;
				flag[i]=1;
				break;
			}
		}
		if(flag[i]!=1){
			this2[i]=1;
			for(j=0;j<num2;j++){
				this1[j]=this1[j]+this[i][j];
				safeseq[count]=i;
				count++;
				printf("P%d->",safeseq[count]);
			}
		}
	}*/
	/*for(i=0;i<num1;i++){
		for(j=0;j<num2;j++){
			if(this[i][j]>this1[j]){
				this2[i]=0;
			}
			else{
				this2[i]=1;
				this1[j]=this1[j]+this[i][j];
				safeseq[count]=i;
				count++;
			}
				
		}*/
		
		
	/*}
	for(i=0;i<num1;i++){
		if(this2[i]=1){
			flag=1;
		}
		else{
			flag=0;
		}
	}
	if(flag=1){
		for(i=0;i<num1;i++){
			printf("P%d->",safeseq[i]);
		}
	}*/
	
	for(i=0;i<num1;i++){
		for(j=0;j<num1;j++){
			if(this2[i]==0){
				int flag=0;
				for(k=0;k<num2;k++){
					if(this[j][k]>this1[k]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					safeseq[count]=j;
					count++;
					this2[j]=1;//this task finished now
					for(a=0;a<num2;a++){
						this1[a]=this1[a]+this[j][a];
					}
				}
			}
		}
	}

}
int checksafe(int num1,int this2[num1]){
	for(int i=0;i<num1;i++){
		if(this2[i]==0){
			return 0;
		}
	}
    return 1;
}
void printsafe(int num,int safeseq[num],int flag1[num]){
	if(checksafe(num,flag1)){
		printf("system is in safe state\n");
		for(int i=0;i<num;i++){
			printf("Safe sequence:P%d->",safeseq[i]);
		}
	}
	else{
		printf("system is not in safe state");
	}		
	
	
	
}		
int main(){
	int n,m;
	
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("Enter the number of resources:");
	scanf("%d",&m);
	int allocation[n][m];
	int max[n][m];
	int available[m];
	int need[n][m];
	printf("Enter available:");
	for(int i=0;i<m;i++){
	scanf("%d",&available[i]);
	}
	int finish[n];
	for(int i=0;i<n;i++){
		finish[i]=0;
	}
	int safe1[n];
	read(n,m,allocation,max);
	calneed(n,m,allocation,max,need);
	safe(n,m,need,available,finish,safe1);
	checksafe(n,finish);
	printsafe(n,safe1,finish);
	return 0;
	
}