#include <assert.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *head = NULL;

void insertAt(int pos, int data);
void runTest(int *expectations);

int main(int argc, char **argv) 
{
  insertAt(2, 15);
  insertAt(0, 32);
  insertAt(1, 5);
  insertAt(3, 87);
  insertAt(10, 58);

  int expectations[5] = {32,5,15,87,58};
  runTest(expectations);
  return 1;
}

void insertAt(int pos, int data)
{
  node *item = (node*) malloc(sizeof(node) * 1);
  item->data = data;
  item->next = NULL;

  if (head == NULL) {
    head = item;
    return;
  }

  if (pos == 0) {
    item->next = head;
    head = item;
    return;
  }

  node *curr = head;
  node *prev;
  int index = 0;

  while (curr != NULL && index != pos) {
    prev = curr;
    curr = curr->next;
    index += 1;
  }

  prev->next = item;
  
  if (index == pos) {
    item->next = curr;
  }
}

void runTest(int *expectations)
{
  node *testRunner = head;
  while(testRunner != NULL) {
    assert(testRunner->data == *expectations);
    testRunner = testRunner->next;
    expectations += 1;
  }
}