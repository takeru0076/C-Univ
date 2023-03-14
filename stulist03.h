/* struct declaration */

typedef struct{
  char class[3];
  int  id;
  char name[15];
  int score;
} Record;

typedef struct node *NodePointer;
struct node {
  Record      data;
  NodePointer next;
}; 


/* prototype declaration */
NodePointer insert(Record);
NodePointer finditem(int);
int listprint(void);
NodePointer make_1node(Record, NodePointer);
NodePointer delete(int);

/* Global Variable head */
NodePointer head;