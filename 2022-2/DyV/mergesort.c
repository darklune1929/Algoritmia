#include <stdio.h>

void merge(int a[],int ini,int med,int fin){
	int t1,t2,i;
	t1= med-ini+1;
	t2 = fin - med;	
	int aux1[t1+1];
	int aux2[t2+1];
	
	for(i=ini;i<=med;i++){
		aux1[i-ini]=a[i];
	}
	aux1[i-ini]=999999;
	
	for(i=med+1;i<=fin;i++){
		aux2[i-med-1]=a[i];
	}
	aux2[i-med-1]=999999;

	int p=0,q=0;
	for(i=ini;i<=fin;i++){
		if(aux1[p]<aux2[q]){
			a[i]=aux1[p];
			p++;
		}else{
			a[i]=aux2[q];
			q++;
		}
	}
}


void mergesort(int a[],int ini,int fin){
	
	if(ini==fin) return;
	
	int med=(ini+fin)/2;
	mergesort(a,ini,med);
	mergesort(a,med+1,fin);
	
	merge(a,ini,med,fin);
}


int main(){
	
	int i,n=6;
	int arr[]={3,5,2,7,1,4};
	
	mergesort(arr,0,n-1);
	
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	
	
	
	
	return 0;
}
