#include <stdio.h>

int lista[10];
int x=0,y=0,flag=0;

int empaca(int i,int n,int peso,int paq[],int rack[]){
	int k;
	if(i==n||peso<0)
		return 0;
	if(paq[i]==peso){
	
		lista[y]=paq[i];
		rack[i]=1;
		
		for(k=0;k<=y;k++)
			printf("%d ",lista[k]);
		printf("\n");		
		for(k=0;k<n;k++){
			if(rack[k]==1){
				if(k%4==0) printf("IA%d ",k/4+1);
				if(k%4==1) printf("IB%d ",k/4+1);	
				if(k%4==2) printf("DA%d ",k/4+1);
				if(k%4==3) printf("DB%d ",k/4+1);
			}
		}
		printf("\n");
		return 1;
	}	
	lista[y++]=paq[i];	
	rack[i]=1;	
	if( empaca(i+1,n,peso-paq[i],paq,rack) )	
		return 1;
	else{
		y--;
		rack[i]=0;
		return empaca(i+1,n,peso,paq,rack);
	}
		
}



int main(){
	
	int paq[]={7,9,8,18,17,12,6,7,14,11,10,15,19,8,12,11};
	int rack[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int peso=23;
	int n=16;
	empaca(0,n,peso,paq,rack);
	
	return 0;
}
