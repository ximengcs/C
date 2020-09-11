Node *list;
Node *current;
Transaction *transaction;

void change_switch( void *one, void *two, ( Node* )( *other )( void *one, void *two ) );
void add_new_trans( Node *list, Transaction *transaction );
Node *delete_trans( Node *list, Node *current );
Node *search( Node *list, Transaction *transaction );
void *edit( Node *current, Transaction *transaction );

void change_switch( void *one, void *two, ( Node* )( *other )( void *one, void *two ) )
{
	two = other( one, two );
}