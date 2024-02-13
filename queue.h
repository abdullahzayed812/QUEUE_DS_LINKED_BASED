#ifndef QUEUE_CLASS_H
#define QUEUE_CLASS_H 1

typedef int QueueEntry;

typedef struct queueNode {
  QueueEntry entry;
  struct queueNode* next;
} QueueNode;

typedef struct queue {
  QueueNode* front;
  QueueNode* rear;
  int size;
} Queue;

void initializeQueue(Queue* pq);
void append(QueueEntry e, Queue* pq);
void serve(QueueEntry* e, Queue* pq);
bool queueFull(Queue* pq);
bool queueEmpty(Queue* pq);
int queueSize(Queue* pq);
void clearQueue(Queue*);
void traverseQueue(Queue* pq, void (*pf)(QueueEntry e));

#endif