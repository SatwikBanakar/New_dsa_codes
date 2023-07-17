#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SIZE 100

struct stack
{
    char data[SIZE];
    int top;
};
void push(struct stack *sptr, char num);
void check(struct stack *sptr,char no[SIZE]);
char pop(struct stack *sptr);

void push(struct stack *sptr, char num)
{
    if(sptr->top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}
char pop(struct stack *sptr)
{
    int num;
    num=sptr->data[sptr->top];
    sptr->top--;
    return num;
}

void check(struct stack *sptr,char no[SIZE])
{
    int ch,stat=1;
    int i=0;
    char temp;
    while(no[i]!='\0')
    {
        ch=no[i];
        push(sptr,ch);
        i++;
    }
    i=0;
    while(no[i]!='\0')
    {
        temp=no[i];
        if(temp!=pop(sptr))
        {
            stat=0;
            break;
        }
        i++;
    }
    if(stat==1)
    {
        printf("%s is a palindrome string",no);
    }
    else
    {
        printf("%s is not a palindrome string",no);
    }


}
int main()
{
    struct stack * sptr;
    struct stack s;
    char pa[SIZE];
    sptr=&s;
    sptr->top=-1;
    scanf("%s",pa);
    check(sptr,pa);
    return 0;
}

//Palindrome stack caR




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SIZE 100
struct stack
{
    char data[SIZE];
    int top;
};
void push(struct stack *sptr, char num);
char pop(struct stack *sptr);
int main()
{
    struct stack * sptr1,* sptr2;
    struct stack s1,s2;
    sptr1=&s1;
    sptr1->top=-1;
    sptr2=&s2;
    sptr2->top=-1;
    int num,i;
    char ch;
    scanf("%d",&num);
    if(num<2)
    {
        printf("More number of cards needed.");
        exit(0);
    }
    for(i=0;i<num;i++) {
scanf(" %c ",&ch);
if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
{
push(sptr1,ch);
}
else {
push(sptr2,ch);
}
}
char ch1;
if(sptr1->top==-1)
    {
       printf("0 ");
    }
    else
    {
        printf("%d ",sptr1->top+1);
    }
    if(sptr2->top==-1)
    {
       printf("0\n");
    }
    else
    {
        printf("%d\n",sptr2->top+1);
    }
    if(sptr1->top==-1)
        {
            printf("-1");
        }
    while(sptr1->top!=-1)
    {
        ch1=pop(sptr1);
        printf("%c ",ch1);
    }
    printf("\n");
    if(sptr2->top==-1)
        {
            printf("-1\n");
        }
    while(sptr2->top!=-1)
    {
        ch1=pop(sptr2);
        printf("%c ",ch1);
    }
    return 0;
}
void push(struct stack *sptr, char num)
{
    if(sptr->top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;
    }
}
char pop(struct stack *sptr)
{
    char num;
    if(sptr->top==-1)
    {
        return -1;
    }
    else
    {
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}


/*OUTPUT

Congratulations, you passed the sample test case.

Click the Submit Code button to run your code against all the test cases.

Input (stdin)

4
A K M E
Your Output (stdout)

2 2
E A
M K
Expected Output

2 2
E A
M K*/





#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define SIZE 100
struct stack
{
    int coin[SIZE];
    int top;
};
void push(struct stack *sptr, int num);
void pop_count_display(struct stack *sptr);
int main()
{
    struct stack * sptr;
    struct stack s;
    sptr=&s;
    sptr->top=-1;
    int c,n,i;
    scanf("%d",&n);
    if(n<0)
    {
        printf("Invalid number of coins");
        exit(0);
    }
    for(i=0;i<n;i++)
{
scanf("%d",&c);
push(sptr,c);
}
pop_count_display(sptr);
 }
void push(struct stack *sptr, int num)
 {
if(sptr->top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sptr->top++;
        sptr->coin[sptr->top]=num;
    }
}
void pop_count_display(struct stack *sptr)
{
        int i,c1=0,c2=0,c5=0,c10=0,c=0;
        for(i=sptr->top;i>=0;i--)
        {
            if(sptr->coin[i]==1)
            {
               c1++;
            }

            else if(sptr->coin[i]==2)
            {
               c2++;
            }
            else if(sptr->coin[i]==5)
            {
               c5++;
            }
            else if(sptr->coin[i]==10)
            {
               c10++;
            }
            else
            {
                c++;
            }
            sptr->top--;
        }
        printf("Coins of 1 re = %d\n",c1);
        printf("Coins of 2 rs = %d\n",c2);
        printf("Coins of 5 rs = %d\n",c5);
        printf("Coins of 10 rs = %d\n",c10);
    printf("Coins of invalid denominations = %d",c);
}
//coin denomination

