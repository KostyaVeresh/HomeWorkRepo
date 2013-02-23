using System;

namespace problem_3
{
    class Program
    {
        private static void BubbleSort(int[] mas, int length)
        {
	        for (int i = 0; i < length - 1; ++i)
	        {
		        for (int j = 0; j < length - 1 - i; ++j)
		        {
			        if (mas[j] > mas[j + 1]) 
                    {
			        	int t = mas[j];
	                    mas[j] = mas[j + 1];
	                    mas[j + 1] = t;
                    }
		        }  
	        }
        }

        static void Main(string[] args)
        {
            const int length = 10;
            Console.WriteLine("Enter array:");
            var mas = new int[length];
            for (int i = 0; i < length; ++i)
            {
                mas[i] = Int32.Parse(Console.ReadLine());
            }
            BubbleSort(mas, length);
            Console.Write("Sorted array: ");
            for (int i = 0; i < length; ++i)
            {
                Console.Write("{0} ", mas[i]);
            }
            Console.ReadLine();
        }
    }
}
