#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "customer_manager.h"

----------------------------------------------------------------------
Uncomment and use the following code if you want

#define UNIT_ARRAY_SIZE 1024

struct UserInfo {
  char *name;                // customer name
  char *id;                  // customer id
  int purchase;              // purchase amount (> 0)
};

struct DB {
  struct UserInfo *pArray;   // pointer to the array
  int curArrSize;            // current array size (max # of elements)
  int numItems;              // # of stored items, needed to determine
			     // # whether the array should be expanded
			     // # or not
};

----------------------------------------------------------------------

/*--------------------------------------------------------------------*/
DB_T
CreateCustomerDB(void)
{
   
  DB_T d;
  
  d = (DB_T) calloc(1, sizeof(struct DB));
  if (d == NULL) {
    fprintf(stderr, "Can't allocate a memory for DB_T\n");
    return NULL;
  }
  d->curArrSize = UNIT_ARRAY_SIZE; // start with 1024 elements
  d->pArray = (struct UserInfo *)calloc(d->curArrSize,
               sizeof(struct UserInfo));
  if (d->pArray == NULL) {
    fprintf(stderr, "Can't allocate a memory for array of size %d\n",
	    d->curArrSize);   
    free(d);
    return NULL;
  }
  return d;
}
/*--------------------------------------------------------------------*/
void
DestroyCustomerDB(DB_T d)
{
  if (d==NULL){
    return 0;
  }/*basic thing?*/
  free(d->pArray);
  free(d);
  /* fill out this function */
  // assert(0);
  // return NULL;
}
/*--------------------------------------------------------------------*/
int
RegisterCustomer(DB_T d, const char *id,
		 const char *name, const int purchase)
{
  if(d ==NULL){
    return -1;
  }
  if(id ==NULL){
    return -1;
  }
  if(name==NULL){
    return -1;
  }
  if (purchase <=0){
    return -1;
  }
  int i,j;
  for(i=0; i< d->curArrSize; i++){
    if(strcmp(d->pArray[i][0] ,id)==0){
      return -1;
    }
    else{
      d->pArray[d->id]=strdup(id);
      id++;
    }
  }
  for(j=0; j<d->curArrSize; j++){
    if(strcmp(d->pArray[j][1],name)==0){
      return -1;
    }
    else{
      d->pArray[d->name]=strdup(name);
      name++;
    }
  d->pArray[d->purchase]=purchase;
  purchase++;
  /* fill out this function */
  //assert(0);
  return 0;
}
/*--------------------------------------------------------------------*/
int
UnregisterCustomerByID(DB_T d, const char *id)
{
  int i;
  int c=0;
  if(d==NULL){
    return -1;
  }
  if(id==NULL){
    return -1;
  }
  for(i=0;i<d->curArrSize;i++){
    if(strcmp(d->pArray[i][0],id)==0){
      free(d->pArray[i]);
      c++;
    }
  }
  if(c!=0){
    return 0;
  }
  else{
    return -1;
  }         
  /* fill out this function */
      // assert(0);
}

/*--------------------------------------------------------------------*/
int
UnregisterCustomerByName(DB_T d, const char *name)
{
  int i;
  int c=0;
  if(d==NULL){
    return -1;
  }
  if(name==NULL){
    return -1;
  }
  for(i=0;i<d->curArrSize;i++){
    if(strcmp(d->pArray[i][1],name)==0){
	free(d->pArray[i]);
	c++;
    }
  }
  if(c!=0){
    return 0;
  }
  else{
    return -1;
  }
  /* fill out this function */
  assert(0);
  return (-1);
}
/*--------------------------------------------------------------------*/
int
GetPurchaseByID(DB_T d, const char* id)
{
  if(d==NULL){
    return -1;
  }
  if(id==NULL){
    return -1;
  }
  int i;
  for(i=0; i<d->curArraySize;i++){
    if(strcmp(d->pArray->id,id)==0){
      return (d->pArray).purchase;
    }
  }
  /* fill out this function */
  // assert(0);
  // return (-1);
}
/*--------------------------------------------------------------------*/
int
GetPurchaseByName(DB_T d, const char* name)
{
  if(d==NULL){
    return -1;
  }
  if(name==NULL){
    return -1;
  }
  int i;
  for(i=0; i<d->curArraySize; i++){
    if(strcmp(d->pArray->name,name)==0){
      return (d->pArray).purchase;
    }
  }
  /* fill out this function */
  // assert(0);
  // return (-1);
}
/*--------------------------------------------------------------------*/
int
GetSumCustomerPurchase(DB_T d, FUNCPTR_T fp)
{
  if(d==NULL){
    return -1;
  }
  if(fp==NULL){
    return -1;
  }
  
  
  /* fill out this function */
  assert(0);
  return (-1);
}
