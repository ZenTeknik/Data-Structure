#include<stdio.h>
#include<stdlib.h>

int main(){

int size;
int *ptr;
printf("Enter the size of an array : \n");
scanf("%d",&size);



ptr=(int * )malloc(size*sizeof(int));

printf("Enter element in the array \n: ");
for(int i=0;i<size;i++){
scanf("%d",&ptr[i]);
}

printf("Elements in the array : \n");
for(int i=0;i<size;i++){
printf("%d",ptr[i]);
}


free(ptr);




return 0;
}
