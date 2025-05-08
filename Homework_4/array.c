#include "array.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct array* array_create()
{
	struct array* a = (struct array*)malloc(sizeof(struct array));
        assert(0 != a);
        memset(a, 0, sizeof(struct array));
	a->size = 0;
	a->capacity = 2;
	a->start = (element_type*)malloc(a->capacity * sizeof(element_type));
	return a;
}

void array_push_back(struct array* a, element_type e)
{
        // TODO
		assert(0 != a);

		if (a->size >= a->capacity) {
			
			if (a->capacity == 0) {
				
				a->capacity = 1;
			}

			else { 
				
				a->capacity += 1;
			}

			a->start = realloc(a->start, a->capacity * sizeof(element_type));
		}

		a->start[a->size] = e;
		a->size++;
}

void array_pop_back(struct array* a)
{
        // TODO
        assert(0 != a);
		
		if (a->size > 0) {
			
			a->size--;
		}
}

void array_insert(struct array* a, size_type index, element_type e)
{
        // TODO
		assert(0 != a);
		assert(index <= a->size);

		if (a->size >= a-> capacity) {
			
			if (a->capacity == 0) {
			
				a->capacity = 1;
			}
			else {
				
				a->capacity += 1;
			}
			
			a->start = realloc(a->start, a->capacity * sizeof(element_type));
		}
		
		for (unsigned int i = a->size; i > index; i--) {
			
			a->start[i] = a->start[i - 1];
		}

		a->start[index] = e;
		a->size++;
}

size_type array_size(struct array* a)
{
	assert(0 != a);
	return a->size;
}

size_type array_capacity(struct array* a)
{
	assert(0 != a);
	return a->capacity;
}

void array_print(struct array* a)
{
	assert(0 != a);
	for (size_type i = 0; i < a->size; ++i) {
		printf("%d ", a->start[i]);
	}
	printf("\nsize = %d", a->size);
	printf("\ncapacity = %d\n\n", a->capacity);
}

int array_empty(struct array* a)
{
	assert(0 != a);
	return a->size == 0;
}
