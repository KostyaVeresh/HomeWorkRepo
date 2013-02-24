using System;

namespace problem_3
{
    class Program
    {
        private static void FillArray(int[,] mas, int length1, int length2)
        {
            int num = 10;
            for (int i = 0; i < length1; ++i)
            {
                for (int j = 0; j < length2; ++j)
                {
                    mas[i, j] = num;
                    Console.Write("{0} ", mas[i, j]);
                    ++num;
                }
                Console.WriteLine();
                Console.WriteLine();
            }
        }

        static void Main(string[] args)
        {
            int length1 = 7;
            int length2 = 7;
            int[,] mas = new int[length1, length2];
            FillArray(mas, length1, length2);
            Console.WriteLine();
            Console.ReadLine();
        }
    }
}