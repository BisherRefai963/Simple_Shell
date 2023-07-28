#include "shell.h"

/**
 * print_list_string - prints only the str element of a list_t linked list
 * @head: pointer to first node
 * Return: size of list
 */

size_t print_list_string(const list_t *head)
{
	size_t n = 0;

	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		n++;
	}
	return (n);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 * Return: array of strings
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t n = list_len(head), i;
	char **ss;
	char *s;

	if (!head || !n)
		return (NULL);
	ss = malloc(sizeof(char *) * (n + 1));
	if (!ss)
		return (NULL);
	for (n = 0; node; node = node->next, n++)
	{
		s = malloc(_strlen(node->str) + 1);
		if (!s)
		{
			for (i = 0; i < n; i++)
				free(ss[i]);
			free(ss);
			return (NULL);
		}

		s = _strcpy(s, node->str);
		ss[n] = s;
	}
	ss[n] = NULL;
	return (ss);
}

/**
 * node_start_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @pre: string to match
 * @next: the next character after prefix to match
 * Return: match node or null
 */

list_t *node_start_with(list_t *node, char *pre, char next)
{
	char *a = NULL;

	while (node)
	{
		a = starts_with(node->str, pre);
		if (a && ((next == -1) || (*a == next)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * list_size - determines length of linked list
 * @head: pointer to first node
 * Return: size of list
 */

size_t list_size(const list_t *head)
{
	size_t n = 0;

	while (head)
	{
		head = head->next;
		n++;
	}
	return (n);
}

/**
 * free_list - frees all nodes of a list
 * @head: address of pointer to head node
 * Return: void
 */

void free_list(list_t **head)
{
	list_t *node, *next_node, *h;

	if (!head || !*head)
		return;
	h = *head;
	node = h;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head = NULL;
}
