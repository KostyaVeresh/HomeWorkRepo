using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_2
{
    public class Program
    {
        /// <summary>
        /// Counts the number of zero elements in array
        /// </summary>
        /// <param name="array"></param>
        /// <returns></returns>
        public static int ZeroElements(int[] array)
        {
            int count = 0;
            for (int i = 0; i < array.Length; ++i)
            {
                if (array[i] == 0)
                    ++count;
            }
            return count;
        }

        static void Main(string[] args)
        {
        }
    }
}
