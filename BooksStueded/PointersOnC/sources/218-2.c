#include <stdio.h>
#include <stdlib.h>

struct {
	float suggest_price;
	float actual_price;
	float sales_tax;
	float licensing_fee;
}a;

struct {
	float suggest_price;
	float actual_price;
	float down_pay;
	float security;
	float monthly;
	int lease;
}b;

struct {
	float actual_price;
	float sales_tax;
	float licensing;
	float down_pay;
	int loan;
	float interest;
	float monthy;
	char name[20];
}c;

struct information{
	char customes_name[20];
	char custoems_adress[40];
	char model[20];
	union{
		struct a *a;
		struct b *b;
		struct c *c;
	}abc;
};
	
int main( void )
{

	return EXIT_SUCCESS;
}