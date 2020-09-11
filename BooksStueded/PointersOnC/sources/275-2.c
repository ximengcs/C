#include <stdlib.h>
#define   TRUE   1
#define   FALSE  0

typedef struct NODE{
	int num;
	struct NODE *next;
}Node;

typedef struct NOTE{
	float num;
	struct NOTE *next;
}Note;

void ergodic_list( Node *head, int (*ergodic)( void *current ) );
void ergodic_int( Node *current );
void ergodic_float( Note *current );

int main( void )
{
	return EXIT_SUCCESS;
}

void search_list( Node *head, int (*ergodic)( void *current ) )
{
	while( head != NULL ){
		ergodic( head );
		head = head->next;
	}
}

void ergodic_int( Node *current )
{
	current = (Node *)current;
	
	while( current != NULL ){
		current = current->next;
	}
}

void ergodic_float( Note *current )
{
	current = (Note *)current;
	while( current != NULL ){
		current = current->next;
	}
}