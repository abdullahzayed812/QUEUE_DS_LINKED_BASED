#include "queue.h"

#include <cstdlib>

void initializeQueue(Queue* pq) {
  pq->front = nullptr;
  pq->rear = nullptr;
  pq->size = 0;
}

void append(QueueEntry e, Queue* pq) {
  QueueNode* pn = (QueueNode*)malloc(sizeof(QueueNode*));
  pn->next = nullptr;
  pn->entry = e;

  if (!pq->rear) {
    pq->front = pn;
  } else {
    pq->rear->next = pn;
  }

  pq->rear = pn;
  pq->size++;

  pn = nullptr;
  free(pn);
}

void serve(QueueEntry* pe, Queue* pq) {
  QueueNode* pn = pq->front;
  *pe = pn->entry;
  pq->front = pn->next;
  free(pn);

  if (!pq->front) {
    pq->rear = nullptr;
  }

  pq->size--;
}

bool queueFull(Queue* pq) { return 0; }

bool queueEmpty(Queue* pq) { return !pq->front; }

int queueSize(Queue* pq) { return pq->size; }

void clearQueue(Queue* pq) {
  while (pq->front) {
    pq->rear = pq->front->next;
    free(pq->front);
    pq->front = pq->rear;
  }

  pq->size = 0;
}

void traverseQueue(Queue* pq, void (*pf)(QueueEntry pe)) {
  for (QueueNode* pn = pq->front; pn; pn = pn->next) {
    (*pf)(pn->entry);
  }
}