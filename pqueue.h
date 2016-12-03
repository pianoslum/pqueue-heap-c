// pqueue header

typedef struct _PQUEUE
{
	uint32 MaxSize;
	uint32 CurrentSize;
	void **Elements; // pointer to void pointers
	uint32 MaxRating; // biggest element possible
	bool32 IsAscendingHeap; // true if the heap should be sorted with the maximum scoring elements first
} PQUEUE;

// given an index to any element in a binary tree stored in a linear array with the root at 1 and 
// a "sentinel" value at 0 these macros are useful in making the code clearer

// the parent is always given by index/2
#define PQ_PARENT_INDEX(i) (i/2)
#define PQ_FIRST_ENTRY (1)

// left and right children are index * 2 and (index * 2) +1 respectively
#define PQ_LEFT_CHILD_INDEX(i) (i*2)
#define PQ_RIGHT_CHILD_INDEX(i) ((i*2)+1)

void PQueueInitialise( PQUEUE *pq, int32 MaxElements, uint32 MaxRating, bool32 bIsAscending );

void PQueueFree( PQUEUE *pq );

int8 PQueuePush( PQUEUE *pq, void *item,  uint32 (*PGetRating) ( void * ) );

int32 PQueueIsFull( PQUEUE *pq );
int32 PQueueIsEmpty( PQUEUE *pq );

void *PQueuePop( PQUEUE *pq, uint32 (*PGetRating) ( void * ) );
