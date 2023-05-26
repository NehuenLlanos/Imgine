#include "garbage-collector.h"
#include "shared.h"

typedef struct Node * List;

struct Node {
    void * ptr;
    List next;
};

List allocated_memory = NULL;

List GetNodeForPtr(void * ptr) {
    List head = allocated_memory;
    boolean found = false;
    while (!found && head != NULL) {
        if (head->ptr == ptr) {
            found = true;
        } else {
            head = head->next;
        }
    }
    return head;
}

void * Malloc(size_t size) {
    List new_node = malloc(sizeof(struct Node));
    void * requested_memory = malloc(size);
    new_node->ptr = requested_memory;
    new_node->next = allocated_memory;
    allocated_memory = new_node;
    return requested_memory;
}

void * Realloc(void * ptr, size_t size) {
    List node = GetNodeForPtr(ptr);
    if (node == NULL) {
        return NULL;
    }

    node->ptr = realloc(ptr, size);
    return node->ptr;
}

void * Calloc(size_t nitems, size_t size) {
    List new_node = malloc(sizeof(struct Node));
    void * requested_memory = calloc(nitems, size);
    new_node->ptr = requested_memory;
    new_node->next = allocated_memory;
    allocated_memory = new_node;
    return requested_memory;
}

void Free(void * ptr) {
    if (ptr == NULL) {
        return;
    }
    
    List previous = NULL;
    List head = allocated_memory;
    boolean found = false;
    while (!found && head != NULL) {
        if (head->ptr == ptr) {
            found = true;
        } else {
            previous = head;
            head = head->next;
        }
    }

    if (!found) {
        return;
    }

    if (previous == NULL) {
        allocated_memory = head->next;
    } else {
        previous->next = head->next;
    }
    free(head->ptr);
    free(head);
}

void FreeAll() {
    while (allocated_memory != NULL) {
        List to_free = allocated_memory;
        allocated_memory = to_free->next;
        free(to_free->ptr);
        free(to_free);
    }
}
