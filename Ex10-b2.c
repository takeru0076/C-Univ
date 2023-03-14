#include <stdio.h>
#include <stdlib.h>    
#include <string.h>        
#include "stulist05.h"

#define N 8

int main()                                                     
{                                                                                                 
  int i,num,status;
  Record data;
  FILE *fp;
  char str[N];
  
  head = make_1node(data, NULL);


  fp = fopen("Student.dat","r");
      while(fscanf(fp,"%s%d%s%d",data.class,&data.id,data.name,&data.score) == 4){
      insert(data);
  }
  fclose(fp);
  num = listprint();
  printf("%d nodes exist in the list.\n\n",num);

  while (1) {
    printf("Input match data(class or ID) -> ");
    status = scanf("%s",str);
    if(status != 1){
      printf("\n");
      break;
    }

    listprint_sel(str);
    
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

void listprint_sel(char *str2){
  char str3[20];
  int len;
    NodePointer n;
    if(('0' <= str2[0]) && (str2[0] <= '9')){
        for (n = head; n->next != NULL; n = n->next){
            sprintf(str3,"%d",n->data.id);
            len = strlen(str2);
            if(strncmp(str2,str3,len) == 0){
              printf("%s %d %s %d\n",n->data.class,n->data.id,n->data.name,n->data.score);
            }
        }
        printf("\n");
    } else {
      for (n = head; n->next != NULL; n = n->next){
      if(strcmp(str2,n->data.class) == 0){
        printf("%s %d %s %d\n",n->data.class,n->data.id,n->data.name,n->data.score);
      }
      }
      printf("\n");
    }
}