void enQueue(CircularQueue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full! Cannot add more elements.\n");
    }
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear = (q->rear + 1) % MAXSIZE;
        q->array[q->rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}