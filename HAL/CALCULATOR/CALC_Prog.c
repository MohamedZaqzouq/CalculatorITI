

#include "CALC_interface.h"
#include "math.h"
#define MAX_EXPR_SIZE 100
s8 infix[MAX_EXPR_SIZE];
#define NULL 0



/**
 * @brief  Using Struct To Build The Stack Which Used To Push And Pop The Operators
 */

struct Stack {
	s32 top;
	unsigned capacity;
	f32* array;
};

/**
 * @brief  createStack function used to create the stack in heap
 * @param  capacity is passed to indicate the stack capacity in memory
 */
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack
	= (struct Stack*)malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array
	= (f32*)malloc(stack->capacity * sizeof(f32));

	if (!stack->array)
		return NULL;

	return stack;
}

/**
 * @brief  isEmpty function used to check weather or not the stack is empty
 * @param  pointer to the stack which allocated
 */

s32 isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

/**
 * @brief  peek function used to get the stack top
 */
f32 peek(struct Stack* stack)
{
	return stack->array[stack-> top];
}

/**
 *  pop function used to get the element which the top index points to
 * param  pointer to the stack which allocated
 * return last in elemet

 */
f32 pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack-> top--];
	return '$';
}

/**
 * push function used to put the element into stack
 * param  pointer to the stack which allocated
 * return void

 */
void push(struct Stack* stack, f32 op)
{
	stack->array[++stack->top] = op;
}


/**
 *  infixToPostfix function used to convert from infix to postfix
 * param  pointer to the array which hold the infix expression
 * return postfix expression

 */

s8* infixToPostfix(s8* infix)
{
	s32 i, j;
	s32 len = strlen(infix);
	s8* postfix = (s8*)malloc(sizeof(s8) * (len + 2));
	s8 stack[MAX_EXPR_SIZE];
	s32 top = -1;

	for (i = 0, j = 0; i < len; i++)
	{
		if (infix[i] == ' ' || infix[i] == '\t')
			continue;

		// If the scanned charcter is operand
		// add it to the postfix expression
		if (isalnum(infix[i])||infix[i]=='.')
		{
			postfix[j++] = infix[i];
		}

		// if the scanned charcter is '('
		// push it in the stack
		else if (infix[i] == '(')
		{
			stack[++top] = infix[i];
		}

	 	// if the scanned charcter is ')'
		// pop the stack and add it to the
		// output string until empty or '(' found
		else if (infix[i] == ')')
		{
			while (top > -1 && stack[top] != '(')
				postfix[j++] = stack[top--];
			if (top > -1 && stack[top] != '(')
				return "Invalid Expression";
			else
				top--;
		}


		else if (isOperator(infix[i]))
		{

			postfix[j] = ' ';
			postfix[++j] = ' ';

			while (top > -1&& precedence(stack[top])>= precedence(infix[i]))
			{

				postfix[j++] = stack[top--];

			}

			stack[++top] = infix[i];
		}
	}

	// Pop all remaining elements from the stack
	while (top > -1)
	{
		if (stack[top] == '(')
		{
			return "Invalid Expression";
		}
		postfix[j++] = stack[top--];
	}
	postfix[j] = '\0';
	return postfix;
}

/**
 *  evaluatePostfix function used to get the value of the enterd expression by converting it into postfix and get its value
 * param  the infix expression
 * return the expression value

 */

f32 evaluatePostfix(s8* exp)
{
	// Create a stack of capacity equal to expression size
	struct Stack* stack = createStack(strlen(exp));
	s32 i;

	// See if stack was created successfully
	if (!stack)
		return -1;

	// Scan all character one by one
	for (i = 0; exp[i]; ++i) {
		// if the character is blank space then continue
		if (exp[i] == ' ')
			continue;

		// If the scanned character is an
		// operand (number here),extract the full number
		// Push it to the stack.
		else if (isdigit(exp[i])||exp[i]=='.') {
			f32 num = 0;
u8 flag=0;
			// extract full number
			while (isdigit(exp[i])||exp[i]=='.') {
				if(exp[i]=='.'){
					flag=1;
					i++;
					continue;
				}
				if(flag==1){
					num = (num * 10 + (f32)(exp[i] - '0'))/10;
				}
				if(flag==0){
				num = num * 10 + (f32)(exp[i] - '0');
				}
				i++;
			}
			i--;

			// push the element in the stack
			push(stack, num);
		}

		// If the scanned character is an operator, pop two
		// elements from stack apply the operator
		else {
			f32 val1 = pop(stack);
			f32 val2 = pop(stack);

			switch (exp[i]) {
			case '+':
				push(stack, val2 + val1);
				break;
			case '-':
				push(stack, val2 - val1);
				break;
			case '*':
				push(stack, val2 * val1);
				break;
			case '/':
				push(stack, val2 / val1);
				break;
			}
		}
	}
	return pop(stack);
}

/**
 * precedence function used to check which operator has higher priority
 * param  the operator
 * return the return precedence of operators
 */


s32 precedence(s8 operator)
{
	switch (operator)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}

/**
 * isOperator function used to check if the scanned character is an operator
 * param  character
 * return
          1 : if operator
          0 : if not operator
 */

s32 isOperator(s8 ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
			|| ch == '^');
}
