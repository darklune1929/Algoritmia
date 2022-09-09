#include <stdio.h>
#include <math.h>
/* 2031  1302  0000 3333*/

int main(){
	int i,j,cont,n=4;
	int sol[n];
	/*cromosoma genetico continuo*/
	for(i=0;i<=3333;i++){
		sol[0]=i%10;        
		sol[1]=(i/10)%10;  
		sol[2]=(i/100)%10;  
		sol[3]=(i/1000)%10; 
		
		if(sol[0]<n && sol[1]<n && sol[2]<n && sol[3]<n
		&& sol[0]!=sol[1] && sol[0]!=sol[2] && sol[0]!=sol[3] 
		&& sol[1]!=sol[2] && sol[1]!=sol[3] && sol[2]!=sol[3])
		{	cont = 0;
			for(j=0;j<n-1;j++){
				if(fabs(sol[j]-sol[j+1])>1) 
					cont++;
			}
			if(cont==n-1)			
				printf("%d %d %d %d\n",sol[0],sol[1],sol[2],sol[3]);
		}
	}
	return 0;
}



