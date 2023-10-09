#include "shell.h"

/**
  * _getenv - this gets the environment variable passed into it
  * @name: this is the environment variable name
  * Return: this returns the value of the environment variable
  */
char *_getenv(char *name)
{
	char *value;
	envi_t *head;

	head = envi;
	while (head != NULL)
	{
		value = _strdup(head->value);
		if (_strcmp(head->name, name) == 0)
		{
			return (value);
		}
		free(value);
		head = head->next;
	}
	return (NULL);
}

/**
  * add_env_end - Add an element at the end of the linked
  * list of environment variables
  * @head: The head of the linked list
  * @name: Name of the environment variable to be added
  * @value: Value of the environment variable to be added
  * Return: The head of the linked list if success and NULL otherwise
  */

envi_t *add_env_end(envi_t **head, char *name, char *value)
{
	envi_t *new_node = NULL;
	envi_t *ptr;

	ptr = *head;
	new_node = malloc(sizeof(envi_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->name = NULL;
	new_node->value = NULL;
	new_node->next = NULL;
	if (ptr == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new_node;
	}
	new_node->name = _strdup(name);
	new_node->value = _strdup(value);
	return (*head);
}


/**
  * build_env_list - This builds up environment variables into
  * a singly linked list
  * Return: The head of the linked list
  */

envi_t *build_env_list(void)
{
	char *name, *n, *v, *value, *curr;
	int i;
	envi_t *head;

	head = NULL;
	i = 0;
	while (environ[i] != NULL)
	{
		curr = malloc(sizeof(char) * _strlen(environ[i]) + 1);
		_strcpy(curr, environ[i]);
		n = strtok(curr, "=");
		v = strtok(NULL, "");
		name = malloc(sizeof(char) * _strlen(n) + 1);
		_strcpy(name, n);
		value = malloc(sizeof(char) * _strlen(v) + 1);
		_strcpy(value, v);
		add_env_end(&head, name, value);
		free(name);
		free(value);
		free(curr);
		i++;
	}
	return (head);
}

/**
  * _setenv - Change or add an environment variable
  *
  * @name: The name of the variable
  * @value: The value that will be saves in the variable
  * Return: Zero on success, -1 on failure
  */

int _setenv(char *name, char *value)
{
	envi_t *temp;
	char *n;

	if (name == NULL || value == NULL)
	{
		return (-1);
	}

	n = _getenv(name);
	if (n == NULL)
	{
		add_env_end(&envi, name, value);
	}
	else
	{
		temp = envi;
		while (temp != NULL)
		{
			if (_strcmp(name, temp->name) == 0)
			{
				free(temp->value);
				temp->value = _strdup(value);
				break;
			}
			temp = temp->next;
		}
		free(n);
	}
	return (0);
}

/**
  * _unsetenv - Delete the variable passed as argument if found
  *
  * @name: The name of the variable to be removes
  * Return: Zero on success, -1 on failure
  */

int _unsetenv(char *name)
{
	char *n = _getenv(name);

	if (n == NULL)
	{
		fprintf(stderr, "Varible does not exist");
		return (1);
	}
	else
	{
		remove_env_list(name);
	}
	free(n);
	return (0);
}
