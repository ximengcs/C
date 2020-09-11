#include <stdio.h>
#include "starfolk.h"
int main(void)
{
	struct bem *pb;
struct bem deb={
	6,{"Berbnazel","Gwolkapwolk"},
	"Arcturan"
};
pb=&deb;
	printf("%s %s is a %d-limed%s",pb->title.first,pb->title.last,pb->limbs,pb->type);
	return 0;
}