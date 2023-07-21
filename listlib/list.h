typedef struct node_t {
	int val;
	struct node_t *next;
	struct node_t *prev;
} Node;

typedef struct list_t {
	Node *head;
	Node *last;
	int length;
} List;

typedef List* Lptr;

void L_init(Lptr);
void L_append(Lptr, int);
void L_pop(Lptr, int);
int L_indexof(Lptr, int);
int L_length(Lptr);
void L_clear(Lptr);
int L_get(Lptr, int);
int L_randomchoice(Lptr);
void L_print(Lptr);