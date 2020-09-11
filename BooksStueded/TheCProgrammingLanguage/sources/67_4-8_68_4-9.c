#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAXOP 100
#define NUMBER '0'
int getop(char []);
void push(double);
double showtop(void);
void clean(void);
void copy(void);
double pop(void);
void exchange(void);
main()
{
	int type;
	double op2;
	char s[MAXOP];
	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("error:zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if(op2 < 0)
					printf("error:mistake number\n");
				else 
					push((int)pop() % (int)op2);
				break;
			case 'c':
				clean();  //清空栈
				break;
			case 'p':
				copy(); //复制栈顶元素
				break;
			case 'e':   //交换栈顶两个元素的值
				exchange();
				break;
			case '\n':
				printf("\t%.8g\n",showtop());
				break;
			case 's':    //sin函数
				push(sin(pop()));  
				break;
			case 'x':    //exp函数
				push(exp(pop()));
				break;
			case 'w':   //pow函数
				op2 = pop();
				push(pow(pop(),op2));
				break;
			default :
				printf("error:unkown command %s\n",s);
				break;
		}
	}
	return 0;
}
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
void exchange(void)
{
	int num;
	num = val[sp];
	val[sp] = val[sp - 1];
	val[sp - 1] = num;
}
void copy(void)
{
	val[sp] = val[sp - 1];
	sp ++;
}
double showtop(void)
{
	if(sp > 0)
		return val[sp - 1];
	else
	{
		printf("error:stack empty\n");
		return 0;
	}
}
void clean(void)
{
	while(sp > 0)
		pop();
}
void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error:stack full,can't push %g\n",f);
}
double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else
	{
		printf("error:stack empty\n");
		return 0;
	}
}
#include <ctype.h>
int getch(void);
void ungetch(int);
int getop(char s[])
{
	int i, c;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c;
	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	ungetch(c);
	return NUMBER;
}
char buf = '\0';
int getch(void)
{
	char buf1 = buf;
	buf = '\0';
	if(buf == EOF)
		return '\n';
	return (buf1 != '\0') ? buf1 : getchar();
}
void ungetch(int c)
{
	buf = c;
}