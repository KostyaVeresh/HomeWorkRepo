using System;

namespace problem_3
{
    class Program
    {
        private static void FillArray(int[,] mas, int length)
        {
            int num = 10;
            for (int i = 0; i < length; ++i)
            {
                for (int j = 0; j < length; ++j)
                {
                    mas[i, j] = num;
                    Console.Write("{0} ", mas[i, j]);
                    ++num;
                }
                Console.WriteLine();
                Console.WriteLine();
            }
        }

        private static void PrintInLine(int[,] mas, int length)
        {
            int sign = 1;
            int way = 1;
            int i = length / 2;
            int j = length / 2;
            while (way < length)
            {
                for (int k = 0; k < way; ++k)
                {
                    Console.Write("{0} ", mas[i, j]);
                    j += sign;
                }
                for (int k = 0; k < way; ++k)
                {
                    Console.Write("{0} ", mas[i, j]);
                    i += sign;
                }
                sign *= -1;
                ++way;
            }
            for (int k = 0; k < length; ++k)
                Console.Write("{0} ", mas[0, k]);
        }

        static void Main(string[] args)
        {
            int length = 7;
            int[,] mas = new int[length, length];
            FillArray(mas, length);
            Console.WriteLine();
            PrintInLine(mas, length);
            Console.WriteLine();
            Console.ReadLine();
        }
    }
}