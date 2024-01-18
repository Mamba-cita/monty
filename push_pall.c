#include "monty.h"

/**
 * check_digit - check if string is a number
 * @param: param to push
 * @line_count: current line number
 * Return: number
 */
int check_digit(char *param, unsigned int line_count)
{
	int num;

	num = atoi(param);
	if (num == 0 && strcmp(param, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}
	return (num);
}

/**
 * m_push - it pushes an element to the stack.
 * @stack: pointer to the stack
 * @line_count: current line number
 * Return: void function
 */
void m_push(Stack *stack, unsigned int line_count)
{
	int num;

	char *param;

	param = strtok(NULL, SEPARATORS);

	if (!param)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}
	num = check_digit(param, line_count);
	push(stack, num);
}

/**
 * m_pall - print the stack
 * @stack: pointer to the stack
 * @line_count: current line of monty file
 * Return: returns void
 */
void m_pall(Stack *stack, __attribute__((unused)) unsigned int line_count)
{
	for (int i = stack->top - 1; i >= 0; i--)
	{
		printf("%d\n", stack->stack[i]);
	}
}
