#include <stdio.h>
#include <stdlib.h>            
#include "stulist01.h"

int main()                                                     
{                                                                                                 
  int i,num,status;
  Record data;

  head = make_1node(data, NULL);
  listprint();

  while (1) {
    printf("Insert new data: (class ID name) -> ");
    status = scanf("%s%d%s%d",data.class,&data.id,data.name,&data.score);
    if(status != 4){
      printf("\n");
      break;
    }
    if (insert(data) == NULL) printf("Data %d is already on the list!\n", data.id);
    listprint();
  }
  return 0;
}





NodePointer insert(Record data)
{
  NodePointer newnode;
 
  if (finditem(data.id) == NULL) {
    newnode = make_1node(data, head->next);
    head->next = newnode;   
    return newnode;
  }
  else return NULL;
}






void listprint(void)
{
  NodePointer n;
  printf("Head - \n");
  for (n = head->next; n != NULL; n = n->next) {
    printf("  %s",n->data.class);
    printf(" %d", n->data.id);
    printf(" %s",n->data.name);
    printf(" %d\n",n->data.score);
  }
  printf("\n");
}






NodePointer finditem(int keydata)
{
  NodePointer n;
  
  for (n = head; n->next != NULL; n = n->next) {
    if (n->next->data.id == keydata) return n;
  } 
  return NULL;
}







NodePointer make_1node(Record data, NodePointer p)
{
  NodePointer n;
 
  if ((n = (NodePointer)malloc(sizeof(struct node))) == NULL) { 
    printf("Error in memory allocation\n");
    exit(8);
  }
 
  n->data = data; 
  n->next = p;

  return n;
}                                   