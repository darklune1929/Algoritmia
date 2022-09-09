#include <stdio.h>
void merge(int A[],int ini,int med, int fin){
	int t1,t2,i,p,q;
	
	t1=med-ini+1;
	t2=fin-med;
	
	int P[t1+1];
	int Q[t2+1];
	
	for(i=ini;i<=med;i++)
		P[i-ini]=A[i];
	
	for(i=med+1;i<=fin;i++)
		Q[i-(med+1)]=A[i];
	
	P[t1]=9999999;Q[t2]=9999999;
	p=q=0;
	for(i=ini;i<=fin;i++)
		if(P[p]<Q[q])
			A[i] = P[p++];
		else
			A[i] = Q[q++];
	
}


void mergesort(int A[],int ini, int fin){
	if(ini==fin)
		return;
	int med = (ini+fin)/2;
	mergesort(A,ini,med);	 // log n
	mergesort(A,med+1,fin); //log n
	merge(A,ini,med,fin);
}
//  log n
int clasifica(int A[],int ini,int fin,int cont){
	if(ini>fin)
		return cont;
	//0 0 0 0 1 1
	int med = (ini+fin)/2;
	
	if(A[med]==0)
		clasifica(A,med+1,fin,med-ini+1+cont);
	else
		clasifica(A,ini,med-1,cont);
		
}



int main(){
	int i,j,n=8,m=6;
	double porc = 0.7,temp;
	
	int lotes[][8]={{0,0,0,1,1,0,2,2},
					{1,0,1,1,1,0,1,0},
					{0,1,1,1,1,1,1,1},
					{1,1,1,1,1,0,1,2},
					{1,0,0,0,0,1,2,2},
					{1,1,0,1,0,1,1,2},
				};
	
	int result[][2]={{6,0},{8,0},{8,0},{7,0},{6,0},{7,0} };
	
	
	for(i=0;i<m;i++) //m * (n*log n)
		mergesort(lotes[i],0,result[i][0]-1);
	/*
	for(i=0;i<m;i++){
		for(j=0;j<result[i][0];j++)
			printf("%d ",lotes[i][j]);		
		printf("\n");
	}
	*/
	for(i=0;i<m;i++){  //m * log n
		int total;
		total=clasifica(lotes[i],0,result[i][0]-1,0);
	 	temp = (double)total / result[i][0];
		if(1-temp>=porc)
			result[i][1]=1;	
		printf("%d\n",result[i][1]);	 
	}
	
	
	
	return 0;
	
	
}
