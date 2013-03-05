using System;

namespace problem_1
{   
    class Program
    {
        static void Main(string[] args)
        {
            Stack stack = new Stack();
            for (int i = 1; i <= 5; ++i)
            {
                stack.Push(i);
            }
            stack.printStack();
            Console.WriteLine("The top of stack: {0}", stack.Top());
            Console.ReadLine();
        }
    }
}
