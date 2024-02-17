#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: Pointer to the hash table
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{ /* Function to delete the hash table */
	unsigned long int i;
	hash_node_t *current, *t;
	/* Check if the hash table pointer is NULL */
	if (!ht)
		return;
		/* Loop through each index of the hash table */
	for (i = 0; i < ht->size; i++)
	{ /* Traverse each linked list and free memory */
		current = ht->array[i];
		while (current)
		{
			free(current->key); /* Free the key memory */
			free(current->value); /* Free the value memory */
			t = current->next; /* Preserve the next node */
			free(current); /* Free the current node */
			/* Move to the next node */
			current = t;
		}
	}
	free(ht->array); /* Free the array of pointers */
	free(ht); /* Free the hash table structure */
} /* End of function */
