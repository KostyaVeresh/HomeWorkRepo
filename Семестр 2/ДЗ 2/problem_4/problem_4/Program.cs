using System;

namespace problem_4
{
    class Program
    {
        private static void GenerateArray(int[,] mas, int length1, int length2)
        {
            Random rnd = new Random();
            for (int i = 0; i < length1; ++i)
            {
                for (int j = 0; j < length2; ++j)
                {
                    mas[i, j] = rnd.Next(90) + 10;
                    Console.Write("{0} ", mas[i, j]);
                }
                Console.WriteLine();
                Console.WriteLine();
            }
        }
         
        private static void BubbleSort(int[,] mas, int length1, int length2)
        {
            for (int i = 0; i < length2 - 1; ++i)
            {
                for (int j = 0; j < length2 - 1 - i; ++j)
                {
                    if (mas[0, j] > mas[0, j + 1])
                        for (int k = 0; k < length1; ++k)
                        {
                            int temp = mas[k, j];
                            mas[k, j] = mas[k, j + 1];
                            mas[k, j + 1] = temp;
                        }                                          
                }
            }
        }

        static void Main(string[] args)
        {
            int length1 = 5;
            int length2 = 7;
            int[,] mas = new int[length1, length2];
            GenerateArray(mas, length1, length2);
            BubbleSort(mas, length1, length2);
            Console.WriteLine();
            Console.Write("Sorted Array:\n\n");
            for (int i = 0; i < length1; ++i)
            {
                for (int j = 0; j < length2; ++j)
                    Console.Write("{0} ", mas[i, j]);
                Console.WriteLine();
                Console.WriteLine();
            }
            Console.ReadLine();
        }
    }
}