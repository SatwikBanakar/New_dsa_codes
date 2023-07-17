#include<stdio.h>
#include<stdlib.h>
int stack[100]; int top=-1;
void random(FILE *p1,int n)
{
    int num=0; int p,q;
    scanf("%d",&p);
    scanf("%d",&q);
    for(int i=0;i<n;i++)
    {
        num = (rand()%(p-q+1))+p;
        fprintf(p1,"%d\n",num);
    }
    fclose(p1);
}
void push(int n,int data){
    if(top == n-1)
        printf("Overflow State: can't add more elements into the stack\n");
    else{
        top+=1;
        stack[top] = data;
    }
}
int pop(){
    // Checking underflow state
    if(top == -1)
        printf("Underflow State: Stack already empty, can't remove any element\n");
    else{
        int x = stack[top];
       // printf("Popping %d out of the stack\n", x);
        top-=1;
        return x;
    }
    return -1;
}
void display(FILE *p5)
{
    for(int i=top;i>=0;i--)
    {
        fprintf(p5,"%d\n",stack[i]);
    }
}
int main()
{
    FILE *p1,*p2,*p3,*p4,*p5; int data;
    int n,op;  int x;
    printf("Enter the numbers\n");
    scanf("%d",&n);
    p1 = fopen("numbers.txt","w");
    p2 = fopen("push.log","w");
    p3 = fopen("pop.log","w");
    p4 = fopen("operation.log","w");
    p5 = fopen("displaystack.log","w");
    random(p1,n);
    p1 = fopen("numbers.txt","r");
    while(1)
    {
        printf("Enter 1 Push Opeartion");
        printf("Enter 2 Pop Operation\n");
        printf("enter 3 exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1: fscanf(p1,"%d",&data);
                    push(n,data);
                    fprintf(p2,"PUSH = %d\n", data);
                    fprintf(p4,"PUSH\n");
                    break;
            case 2: x=pop();
                    fprintf(p3,"POP = %d\n",x);
                    fprintf(p4,"POP\n");
                    break;
            case 3:display(p5);
            fprintf(p4,"EXIT\n");
            exit(0); break;
        }
    }

}
