#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void insert(node **head, int data);
void runTest(node *head, int *expectations);

int main(int argc, char **argv) {
  node *head = NULL;
  int expectations[3] = {32, 9, 48};

  insert(&head, 32);
  insert(&head, 9);
  insert(&head, 48);

  runTest(head, expectations);

  return 1;
}

void insert(node **head, int data)
{
  node *item = (node*) malloc(sizeof(node) * 1);
  item->data = data;
  item->next = NULL;

  if (*head == NULL) {
    *head = item;
    return;
  }

  node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = item;
}

void runTest(node *head, int *expectations)
{
  node *testRunner = head;
  while (testRunner != NULL) {
    assert(testRunner->data == *expectations);
    expectations += 1;
    testRunner = testRunner->next;
  }
}