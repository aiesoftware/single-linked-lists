#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *data;
  struct node *next;
} node;

node *head = NULL;

void insert(char *data);
void runTest(char **expectations);

int main(int argc, char **argv) 
{
  insert("kiwi fruit");
  insert("apple");
  insert("lemon");
  insert("banana");

  char *expectations[4] = {"apple","banana","kiwi fruit","lemon"};
  runTest(expectations);
  return 1;
}

void insert(char *data)
{
  node *item = (node*) malloc(sizeof(node) * 1);
  item->data = (char*) malloc(sizeof(strlen(data)) * 1);
  strcpy(item->data, data);
  item->next = NULL;

  if (head == NULL) {
    head = item;
    return;
  }

  node *curr = head;
  node *prev;

  while (curr != NULL && strcmp(data, curr->data) >= 0) {
    prev = curr;
    curr = curr->next;
  }

  if (curr == head) {
    item->next = head;
    head = item;
    return;
  }

  prev->next = item;

  if (curr != NULL) {
    item->next = curr;
  }
}

void runTest(char **expectations)
{
  node *testRunner = head;
  while(testRunner != NULL) {
    assert(strcmp(testRunner->data, *expectations) == 0);
    testRunner = testRunner->next;
    expectations += 1;
  }
}