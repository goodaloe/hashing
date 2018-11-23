
/* ID 2015114727        - REPLACE WITH YOUR ID
 * NAME Kim Ho-JEong       - REPLACE WITH YOUR NAME */


#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define Page 10

#define Key(key) key%Page

//reference: http: //huiyu.tistory.com/entry/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EC%B2%B4%EC%9D%B4%EB%8B%9D-%ED%95%B4%EC%8B%9C-%ED%85%8C%EC%9D%B4%EB%B8%94Chaining-Hash-Table

// These are encoded IDs, different from actual ones
#define NUM_STUDENTS	49
static long students_id[NUM_STUDENTS] = {
  40116104020, 40116104024, 40116104098, 40116104166, 40116104178,
  40116104193, 40116104262, 40116104290, 40116104295, 40116104301,
  40116104321, 40116104336, 40116104372, 40116104382,
  40117037217, 40117104017, 40117104049, 40117104081, 40117104086,
  40117104129, 40117104132, 40117104189, 40117104214, 40117104277,
  40117104307, 40117104313, 40117104449, 40117104463, 40117110170,
  40117110576, 40117113099, 40117113964, 40117114727, 40117117785,
  40117118653, 40117114989, 40117115012, 40119104004, 40119104051,
  40119104090, 40119104117, 40119104176, 40119104184, 40119104293,
  40119104325, 40119104339, 40119104404, 40119104406, 40119118005,
};


/////////////////////////////////////////////////////////////////////
// if necessary, your functions can be added
/////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////
struct NODE {
	int data;
	struct NODE *next;
};


void freelist(struct NODE *head)
{
	struct NODE *next;
	while (head) {
		next = head->next;
		free(head);
		head = next;
	}
}


/////////////////////////////////////////////
NODE * hashTable[Page];


void  Insert(int key, NODE* node)
{
	int hash_key = Key(key);
	if (hashTable[hash_key] == NULL)
	{
		hashTable[hash_key] = node;
	}
	else
	{
		node->next = hashTable[hash_key];
		hashTable[hash_key] = node;
	}
}


void printlist(struct NODE *head)
{
	for (int i = 0; i < Page; i++)
	{
		printf("page:%d\n", i);
		if (hashTable[i] != NULL)
		{
			NODE* node = hashTable[i];
			while (node->next)
			{
				printf("%d , ", node->data);
				node = node->next;
			}
			printf("%d\n\n", node->data);
		}
	}



}
////

/////////////////////////////////////////////////////////////////////
// midterm problem 2
// implement hash function that is efficient for students_id
/////////////////////////////////////////////////////////////////////

int main() {

	int i, N;
	int val;
	struct NODE *head;

	head  = NULL;

	for (int i = 0; i < 49; i++)
	{
		NODE* node = (NODE*)malloc(sizeof(NODE));
		node->data = students_id[i];
		node->next = NULL;
		Insert(node->data, node);
	}



	printlist(head);

	// free memory
	freelist(head);

	return 0;
}