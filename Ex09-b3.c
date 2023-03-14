#include <stdio.h>
#include <stdlib.h>            
#include "stulist03.h"

int main()                                                     
{                                                                                                 
  int i,num,status,ope,id;
  Record data;
  FILE *fp;
  NodePointer q;
  
  head = make_1node(data, NULL);


  fp = fopen("Student.dat","r");
      while(fscanf(fp,"%s%d%s%d",data.class,&data.id,data.name,&data.score) == 4){
      insert(data);
  }
  fclose(fp);
  num = listprint();
  printf("%d nodes exist in the list.\n\n",num);

  while (1) {
    printf("Chose operation (1: Insert, 0: delete, ^D: Finish) -> ");   if(scanf("%d",&ope) == EOF)break;
    if(ope == 0){
        printf("Delete ID -> ");   scanf("%d",&id);
        q = delete(id);
        if(q == NULL){
            printf("ID %d is not found.\n",id);
            num = listprint();
            printf("%d nodes exist in the list.\n\n",num); 
        } else {
            num = listprint();
            printf("%d nodes exist in the list.\n\n",num);
        }
    }
    if(ope == 1){
    printf("Insert new data: (class ID name) -> ");
    status = scanf("%s%d%s%d",data.class,&data.id,data.name,&data.score);
    if(status != 4){
      printf("\n");
      break;
    }
    if (insert(data) == NULL) printf("ID %d is already on the list!\n", data.id);
    num = listprint();
    printf("%d nodes exist in the list.\n\n",num);
    }
  }
  return 0;
}




NodePointer insert(Record data)
{
  NodePointer newnode,p;

 
  if (finditem(data.id) == NULL) {
      p = head;
      while(p->next != NULL) {
            p = p->next;
      }
       newnode = make_1node(data, NULL);
    p->next = newnode;
    return newnode;
  }
  else return NULL;
}




int listprint(void)
{
  int count = 0;
  NodePointer n;
  printf("Head - \n");
  for (n = head->next; n != NULL; n = n->next) {
    printf("  %s",n->data.class);
    printf(" %d", n->data.id);
    printf(" %s",n->data.name);
    printf(" %d\n",n->data.score);
    count++;
  }
  return count;
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




NodePointer delete(int keydata){
    NodePointer n,delnode;

    if((n = finditem(keydata)) != NULL){
        delnode = n->next;
        n->next = delnode->next;
        free(delnode);
        return n;
    }
    else
    {
         return NULL;
    }
    
}