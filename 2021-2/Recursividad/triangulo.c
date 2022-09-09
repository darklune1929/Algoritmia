#include <stdio.h>

void triangulo(int a,int b){
	int i;
	if(a>b)
		return;
	else{
		for(i=0;i<a;i++)   //a=3
			printf(" * "); //***  
		printf("\n");      //a=4
						   //****
   						   //a=5
						   //*****	
		triangulo(a+1,b);  
							//*****
		for(i=0;i<a;i++)	//****
							//***
			printf(" * "); 
		printf("\n");	
	}	

}
void pinta(char c,int n){
	if(n==0)	
		return;
	printf(" %c ",c);
	pinta(c,n-1);	
}

void triangulo2(int a,int b){
	int i;
	if(a>b)
		return;
	else{
		pinta('*',a);   //***
		printf("\n");   //****   
		triangulo2(a+1,b);  
		pinta('?',a);  //****
		printf("\n");  //***	
	}	
}

int main(){
	
	triangulo2(3,5);
	
}
