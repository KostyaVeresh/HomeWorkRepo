using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem
{
    public class Program
    {
        /// <summary>
        /// Bubble sort for different types of data arrays
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="data"></param>
        /// <param name="length"></param>
        /// <param name="comparator"></param>
        public static void BubbleSort<T>(ref T[] data, int length, Comparator<T> comparator)
        {
            for (int i = 0; i < length - 1; ++i)
            {
                for (int j = 0; j < length - 1 - i; ++j)
                {
                    if (comparator.Compare(data[j], data[j + 1]))
                    {
                        T t = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = t;
                    }
                }
            }
        }

        static void Main(string[] args)
        {
        }
    }
}
