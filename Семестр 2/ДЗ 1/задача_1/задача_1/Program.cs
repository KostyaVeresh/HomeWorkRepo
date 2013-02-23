using System;

namespace задача_1
{
    class Program
    {
        private static long Factorial(int n)
        {
            if (n == 0)
                return 1;
            return n * Factorial(n - 1);
        }

        static void Main(string[] args)
        {
            int num = 0;
            Console.Write("Enter number: ");
            num = Int32.Parse(Console.ReadLine());
            Console.WriteLine("Result: {0}", Factorial(num));
            Console.ReadLine();
        }
    }
}