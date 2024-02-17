#include "hash_tables.h"

/**
 * hash_table_get - get value of a key in a hash table
 *
 * @ht: pointer to the hash table
 * @key: key of the node to update
 *
 * Return: string value on success, NULL on failure
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{/*const char *key;*/
	unsigned long int k_index;/*unsigned long int k_index;*/
	hash_node_t *current;/*hash_node_t *current;*/
	/*check validation*/
	if (ht == NULL || key == NULL || key[0] == '\0' || ht->size == 0)
    /*ht->size == 0;*//*ht->array == NULL;*/
		return (NULL);

	/*get index*/
	k_index = key_index((unsigned char *)key, ht->size);
    /*key_index(key, ht->size);*/

	if (ht->array[k_index] == NULL)
		return (NULL);
	current = ht->array[k_index]; /*get first node*/

	while (current) /*update the value*/
	{ /*current = current->next;*/
		if (strcmp(current->key, key) == 0)
/*return (current->value);*/
			return (current->value); /*return NULL on failure*/

		current = current->next;
	} /*return NULL on failure*/
	return (NULL); /*return NULL on failure*/
}
