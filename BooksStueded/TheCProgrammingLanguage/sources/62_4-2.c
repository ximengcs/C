#include <stdio.h>
#include <ctype.h>
double atof(char s[]);
int main(void)
{
	char num[10];
	gets(num);
	printf("%lf",atof(num));
	return 0;
}
double atof(char s[])
{
	double val, power, num;
	int i, sign, a, zhishu = 1;
	for(i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	num = sign * val / power;
	if(s[i] == 'e')
		i++;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(a = 0; isdigit(s[i]); i++)
		a = a * 10 + (s[i] - '0');
	if(sign == 1)
	{
		for(i = 0; i < a; i++)
			zhishu *= 10;
		return num * zhishu;
	}
	else
	{
		for(i = 0; i < a; i++)
			zhishu *= 10;
		return num / zhishu;
	}
}