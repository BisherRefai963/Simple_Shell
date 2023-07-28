#include "shell.h"

/**
 * new_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 * Return: size of list
 */

list_t *new_node(list_t **head, const char *str, int num)
{
	list_t *new_h;

	if (!head)
		return (NULL);
	new_h = malloc(sizeof(list_t));
	if (!new_h)
		return (NULL);
	_memset((void *)new_h, 0, sizeof(list_t));
	new_h->num = num;
	if (str)
	{
		new_h->str = _strdup(str);
		if (!new_h->str)
		{
			free(new_h);
			return (NULL);
		}
	}
	new_h->next = *head;
	*head = new_h;
	return (new_h);
}

/**
 * delete_node - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 * Return: 1 on success, 0 on failure
 */

int delete_node(list_t **head, unsigned int index)
{
	list_t *n, *pn;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		n = *head;
		*head = (*head)->next;
		free(n->str);
		free(n);
		return (1);
	}
	n = *head;
	while (n)
	{
		if (i == index)
		{
			pn->next = n->next;
			free(n->str);
			free(n);
			return (1);
		}
		i++;
		pn = n;
		n = n->next;
	}
	return (0);
}

/**
 * add_tail - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */

list_t *add_tail(list_t **head, const char *str, int num)
{
	list_t *tail, *n;

	if (!head)
		return (NULL);

	n = *head;
	tail = malloc(sizeof(list_t));
	if (!tail)
		return (NULL);
	_memset((void *)tail, 0, sizeof(list_t));
	tail->num = num;
	if (str)
	{
		tail->str = _strdup(str);
		if (!tail->str)
		{
			free(tail);
			return (NULL);
		}
	}
	if (n)
	{
		while (n->next)
			n = n->next;
		n->next = tail;
	}
	else
		*head = tail;
	return (tail);
}

/**
 * get_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 * Return: index of node or -1
 */

ssize_t get_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

/**
 * print_list - prints elements of a linked list
 * @head: pointer to first node
 * Return: size of list
 */

size_t print_list(const list_t *head)
{
	size_t n = 0;

	while (head)
	{
		_puts(convert_number(head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		n++;
	}
	return (n);
}
