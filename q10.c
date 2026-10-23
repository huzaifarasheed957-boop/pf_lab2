int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int multi(int a,int b){
    return a*b;
}
float divide(float a,float b){
    return a/b;
}

#include <stdio.h>

int main(){
    int choice,a,b;
    printf("enter the choice :");
    scanf("%d",&choice);
    printf("enter the value of first number:");
    scanf("%d",&a);
      printf("enter the value of second number:");
    scanf("%d",&b);
    if (choice<1||choice>5){
        printf("invalid choice!");

    }else if (choice=1){
        int result=add(a,b);
        printf("%d",result);
    }else if (choice=2){
       int result=sub(a,b);
        printf("%d",result); 
    }else if (choice=3){
        int result=multi(a,b);
        printf("%d",result);
    }else if(choice=4){
        float result=divide(a,b);
        printf("%d",result);
    }

    return 0;
}