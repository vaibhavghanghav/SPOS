#include <stdio.h>
#include <stdlib.h>

// Define the number of frames
#define FRAMES 3

// Define the queue data structure
struct queue {
  int data;
  struct queue *next;
};

// Create a new queue node
struct queue *new_node(int data) {
  struct queue *node = (struct queue *)malloc(sizeof(struct queue));
  node->data = data;
  node->next = NULL;
  return node;
}

// Add a node to the end of the queue
void enqueue(struct queue **head, int data) {
  struct queue *node = new_node(data);
  if (*head == NULL) {
    *head = node;
  } else {
    struct queue *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = node;
  }
}

// Remove the node from the front of the queue
int dequeue(struct queue **head) {
  if (*head == NULL) {
    return -1;
  } else {
    int data = (*head)->data;
    *head = (*head)->next;
    return data;
  }
}

// Check if a node is present in the queue
int is_present(struct queue *head, int data) {
  struct queue *current = head;
  while (current != NULL) {
    if (current->data == data) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

// FIFO page replacement algorithm
int fifo(int reference_string[], int n, int frames) {
  // Initialize the queue
  struct queue *head = NULL;

  // Initialize the page fault count
  int page_faults = 0;

  // Iterate over the reference string
  for (int i = 0; i < n; i++) {
    // Check if the page is present in the queue
    if (!is_present(head, reference_string[i])) {
      // Page fault
      page_faults++;

      // Remove the oldest page from the queue
      int oldest_page = dequeue(&head);

      // Add the new page to the queue
      enqueue(&head, reference_string[i]);
    }
  }

  return page_faults;
}

// Main function
int main() {
  // Reference string
  int reference_string[] = {1, 3, 0, 3, 5, 6, 3};

  // Number of frames
  int frames = FRAMES;

  // Calculate the number of page faults
  int page_faults = fifo(reference_string, sizeof(reference_string) / sizeof(reference_string[0]), frames);

  // Print the number of page faults
  printf("Number of page faults: %d\n", page_faults);

  return 0;
}