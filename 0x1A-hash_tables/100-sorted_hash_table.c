#include "hash_tables.h"
#include "php_hash_table.h"

/**
 * shash_table_create - create a hash table and return a pointer to it
 * @size: size of the hash table
 * Return: a pointer to the hash table or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shash_table;

	shash_table = malloc(sizeof(shash_table_t));
    /* Allocate memory for the hash table */
	if (!shash_table)
		return (NULL); /* Check if memory allocation failed */
	shash_table->array = malloc(sizeof(shash_node_t *) * size);
    /* Allocate memory for the array */
	if (!shash_table->array)
	{
		free(shash_table); /* Free the previously allocated memory */
		return (NULL); /* Return NULL if memory allocation failed */
	}
	shash_table->size = size; /* Set the size of the hash table */
	shash_table->shead = shash_table->stail = NULL;
    /* Initialize the sorted linked list pointers */
	return (shash_table); /* Return a pointer to the hash table */
}

/**
 * shash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key of the node
 * @value: value of the node
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{ /* Function to set a key-value pair in the hash table */
	shash_node_t *node, *cur_node;
	int index;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0); /* Check for valid input parameters */
	index = key_index((const unsigned char *)key, ht->size);
	cur_node = ht->array[index];
    /* Get the current node at the calculated index */
	while (cur_node)
	{ /* Traverse through the linked list */
		if (strcmp(cur_node->key, key) == 0)
		{ /* Update value if the key already exists */
			free(cur_node->value);
			cur_node->value = strdup(value);
			return (1);
		}
		cur_node = cur_node->next;
	}
	node = create_node(key, value); /* Create a new node */
	if (!node)
		return (0); /* Return 0 if node creation fails */
	node->next = ht->array[index]; /* Update pointers */
	ht->array[index] = node;
	sorted_list(ht, node); /* Maintain the sorted linked list */
	return (1); /* Return success */
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the hash table
 * @key: key to retrieve the value associated with
 * Return: the value of the key
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{ /* Function to retrieve a value associated with a key */
	shash_node_t *cur_node;
	int index;

	if (!ht || !key)
		return (NULL); /* Check for valid input */
	index = key_index((const unsigned char *)key, ht->size); /* Get the index */
	cur_node = ht->array[index]; /* Get the node at the index */
	while (cur_node)
	{ /* Traverse through the linked list */
		if (strcmp(cur_node->key, key) == 0)
			return (cur_node->value); /* Return value if key is found */
		cur_node = cur_node->next;
	}
	return (NULL); /* Return NULL if key is not found */
}

/**
 * shash_table_delete - delete the hash table
 * @ht: the hash table
 */

void shash_table_delete(shash_table_t *ht)
{ /* Function to delete the hash table */
	unsigned long int i;
	shash_node_t *cur, *temp;

	if (!ht) /* Check if hash table is NULL */
		return;
	for (i = 0; i < (ht->size); i++)
	{ /* Iterate through the array of the hash table */
		if (ht->array[i] != NULL)
		{ /* Check if the array element is not NULL */
			cur = ht->array[i]; /* Get the current node */
			while (cur)
			{ /* Traverse through the linked list */
				temp = cur->next; /* Preserve the next node */
				free(cur->key); /* Free the key memory */
				free(cur->value); /* Free the value memory */
				free(cur); /* Free the node */
				cur = temp; /* Move to the next node */
			}
		}
	}
	free(ht->array); /* Free the array memory */
	free(ht); /* Free the hash table memory */
}
