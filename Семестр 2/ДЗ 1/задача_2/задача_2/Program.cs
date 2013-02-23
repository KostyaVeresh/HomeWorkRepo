using System;

namespace задача_2
{
    class Program
    {
        private static int FibonacciNum(int n)
        {
            if (n == 1 || n == 2)
                return 1;
            else
            {
                int num1 = 1;
                int num2 = 1;
                for (int i = 1; i <= n; ++i)
                {
                    int tmp = num1;
                    num1 = num1 + num2;
                    num2 = tmp;
                }
                return num1;
            }
        }
        static void Main(string[] args)
        {
            int num = 0;
            Console.Write("Enter number of Fibonacci numbers: ");
            num = Int32.Parse(Console.ReadLine());
            for (int i = 1; i <= num; ++i)
                Console.Write("{0} ", FibonacciNum(i));
            Console.ReadLine();
        }
    }
}