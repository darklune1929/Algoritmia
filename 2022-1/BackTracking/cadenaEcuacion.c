#include <stdio.h>
#include <stdlib.h>
void solveParenthesisAll(int currentPosition,int leftTotal,int rightTotal,int leftRemove,int rightRemove,int strlength,char* string
,int* solutionArray){
    if(currentPosition==strlength){
        if((leftRemove==0) && (rightRemove==0)){
            printf("\nUna solución: ");
            for(int i=0;i<strlength;i++){
                if(solutionArray[i]){
                    printf("%c",string[i]);
                }
            }
        }
    } else{
        if((string[currentPosition] == '(') && (leftRemove>0)){
            solveParenthesisAll(currentPosition+1,leftTotal,rightTotal,leftRemove-1,rightRemove,strlength,string,solutionArray);
        } else if((string[currentPosition]==')') && (rightRemove>0)){
            solveParenthesisAll(currentPosition+1,leftTotal,rightTotal,leftRemove,rightRemove-1,strlength,string,solutionArray);
        }
        solutionArray[currentPosition] = 1;

        if((string[currentPosition]!='(') && (string[currentPosition]!=')')){
            solveParenthesisAll(currentPosition+1,leftTotal,rightTotal,leftRemove,rightRemove,strlength,string,solutionArray);
        } else if(string[currentPosition]=='('){
            solveParenthesisAll(currentPosition+1,leftTotal+1,rightTotal,leftRemove,rightRemove,strlength,string,solutionArray);
        }

        solutionArray[currentPosition] = 0;
    }
}
int main(){
    int strlength;
    printf("Ingresar cantidad de caracteres a leer: ");
    scanf("%d",&strlength);

    char* string = (char*)malloc(strlength*sizeof(char));
    printf("Ingrese la cadena: ");
    for(int i=0;i<strlength;i++){
        scanf("%c",&string[i]);
    }

    printf("Se leyo el string: ");
    for(int i=0;i<strlength;i++){
        printf("%c",string[i]);
    }
    int* solutionArray = (int*)calloc(strlength,sizeof(int));

    int left=0;
    int right=0;
    for(int i=0;i<strlength;i++){
        if(string[i]=='('){
            left++;
        } else if(string[i]==')'){
            right = ((left==0) ? (right+1) : left);
            left = ((left>0) ? (left-1) : left);
        }
    }
    solveParenthesisAll(0,0,0,left,right,strlength,string,solutionArray);
    return 0;
}