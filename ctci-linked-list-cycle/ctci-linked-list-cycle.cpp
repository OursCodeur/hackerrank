/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
struct Node {
int data;
struct Node* next;
}
*/

bool has_cycle(Node* head) {

	// See Floyd's Tortoise and Hare pointer algorithm here : 
	// https://en.wikipedia.org/wiki/Cycle_detection#Floyd.27s_Tortoise_and_Hare

	Node* tortoise = head;
	Node* hare = head;

	while (hare != NULL && hare->next != NULL) {

		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare) {
			return true;
		}
	}

	return false;
}
