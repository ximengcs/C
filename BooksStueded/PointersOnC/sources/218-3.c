#include <stdlib.h>

struct a{
	unsigned dst_reg  : 3;
	unsigned dst_mode : 3;
	unsigned opcode   : 10;
};

struct b{
	unsigned dst_reg  : 3;
	unsigned dst_mode : 3;
	unsigned src_reg  : 3;
	unsigned src_mode : 3;
	unsigned opcode   : 4;
};

struct c{
	unsigned offset   : 8;
	unsigned opcode   : 8;
};

struct d{
	unsigned dst_reg  : 3;
	unsigned dst_mode : 3;
	unsigned src_reg  : 3;
	unsigned opcode   : 7;
};

struct e{
	unsigned opcode   : 16;
};

typedef struct {
	struct e addr;
	struct a misc;
	struct b branch;
	struct c sgl_op;
	struct d reg_src;
	struct e dbl_op;
}all;

int main( void )
{
	
	return EXIT_SUCCESS;
}