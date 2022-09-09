#include <stdio.h>

void merge(int A[],int ini,int med,int fin){
	int i;
	// 5,2,7,10,8,1,4
	//  5,2,7,10   8,1,4
	int l1=(med+1)-ini;
	int l2=fin-med;
	
	int p[l1+1];
	int q[l2+1];
	p[l1]=9999999;
	
	for(i=ini;i<=med;i++)
		p[i-ini]=A[i];
	
	q[l2]=9999999;
	
	for(i=med+1;i<=fin;i++)
		q[i-med-1]=A[i];	
	int j=0,k=0;	
	for(i=ini;i<=fin;i++)	
		if(p[j] < q[k])	
			A[i]=p[j++];
		else
			A[i]=q[k++];	
			
}


void mergesort(int A[],int ini,int fin){
	if(ini==fin)
		return;
	int med=(ini+fin)/2;
	mergesort(A,ini,med);
	mergesort(A,med+1,fin);
	merge(A,ini,med,fin);
}

int main(){
	int A[]={5,2,7,10,8,1,4};
	int i,n=7;
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	mergesort(A,0,n-1);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",A[i]);	
	
}


