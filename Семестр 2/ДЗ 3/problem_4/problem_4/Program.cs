using System;

namespace problem_4
{
    public class Program
    {
        /// <summary>
        /// Counts the result of expression in postfix form.
        /// </summary>
        /// <param name="stack"></param>
        /// <param name="str"></param>
        public static void StackMachine(Stack stack, string str)
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
                            if (op1 == 0)
                                throw new Exception("You can't devide by zero.");
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
