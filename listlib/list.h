typedef struct node_t {
	int val;
	struct node_t *next;
	struct node_t *prev;
} Node;

Node *L_append(int);
void L_pop(int);
Node *L_indexof(int val);
int L_length(void);
void L_clear(void);
int L_get(int);
