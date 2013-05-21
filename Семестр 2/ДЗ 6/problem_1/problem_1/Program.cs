using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_1
{
    public class Program
    {
        // takes list of int elements and function, returns new list
        public static List<int> Map(List<int> list, Func<int, int> function)
        {
            List<int> newList = new List<int>();
            for (int i = 0; i < list.Count; ++i)
                newList.Add(function(list[i]));
            return newList;
        }

        static void Main(string[] args)
        {
        }
    }
}
