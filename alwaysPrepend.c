#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *head = NULL;

void insert(int data);
void runTest(int *expectations);

int main(int argc, char **argv)
{
  int expectations[3] = {48, 9, 32};

  insert(32);
  insert(9);
  insert(48);

  runTest(expectations);
  return 1;
}

void insert(int data)
{
  node *item = (node*) malloc(sizeof(node) * 1);
  item->data = data;
  item->next = NULL;

  if (head == NULL) {
    head = item;
    return;
  }

  item->next = head;
  head = item;

}

void runTest(int *expectations)
{
  node *testRunner = head;
  while(testRunner != NULL) {
    assert(testRunner->data == *expectations);
    expectations += 1;
    testRunner = testRunner->next;
  }
}