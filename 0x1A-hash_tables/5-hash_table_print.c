#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: Pointer to the hash table
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{/*const hash_table_t *ht;*/
	unsigned long int i; /*unsigned long int i;*/
	int flag = 0; /*int flag = 0;*/
	hash_node_t *current;
	/*check validation*/
	if (ht == NULL)
		return; /*return void on success*/

	printf("{"); /*print open curly bracket*/
	for (i = 0; i < ht->size; i++) /*for (i = 0; i < ht->size; i++)*/
	{

		if (ht->array[i])
		{
			current = ht->array[i];

			while (current)
			{
				if (flag)/*flag = 1;*/
					printf(", ");
				printf("'%s': '%s'", current->key, current->value);
				current = current->next;
				flag = 1;
			}
		}
	}
	printf("}\n");
}
