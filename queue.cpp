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