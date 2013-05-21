using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_3
{
    public class Program
    {
        // takes list of int elements, start value and function, returns new list
        public static int Fold(List<int> list, int start, Func<int, int, int> function)
        {
            int result = start;
            for (int i = 0; i < list.Count; ++i)
            {
                result = function(result, list[i]);
            }
            return result;
        }

        static void Main(string[] args)
        {
        }
    }
}
