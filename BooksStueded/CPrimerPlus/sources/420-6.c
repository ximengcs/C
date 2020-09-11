#include <stdio.h>
typedef struct lens{
	float foclen;
	float fstop;
	char brand[30];
}LENS;
int main(void)
{
	LENS i={500.00,2.0,"Remarkatar"};
	fprintf(stdout,"焦距长度为：%.0fmm,孔径为：f/%.1f的%s镜头",i.foclen,i.fstop,i.brand);
	return 0;
}