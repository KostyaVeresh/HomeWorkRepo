using System;

namespace problem_4
{
    class Program
    {
        static void StackMachine(Stack stack, string str)
        {
            for (int i = 0; i < str.Length; ++i)
            {
                char sym = str[i];
                switch (sym)
                {
                    case '+':
                        {
                            int op1 = stack.Pop();
                            int op2 = stack.Pop();
                            int result = op2 + op1;
                            stack.Push(result);
                        }
                        break;
                    case '-':
                        {
                            int op1 = stack.Pop();
                            int op2 = stack.Pop();
                            int result = op2 - op1;
                            stack.Push(result);
                        }
                        break;
                    case '*':
                        {
                            int op1 = stack.Pop();
                            int op2 = stack.Pop();
                            int result = op2 * op1;
                            stack.Push(result);
                        }
                        break;
                    case '/':
                        {
                            int op1 = stack.Pop();
                            int op2 = stack.Pop();
                            int result = op2 / op1;
                            stack.Push(result);
                        }
                        break;
                    case ' ':
                        break;
                    default:
                        stack.Push(sym - '0');
                        break;
                }
            }
        }

        static void Main(string[] args)
        {
            Stack stack = new StackOnList();
            Console.WriteLine("Write an expression in postfix form:");
            string str = Console.ReadLine();
            StackMachine(stack, str);
            Console.Write("Result: " + stack.Top());
            Console.ReadLine();
        }
    }
}
