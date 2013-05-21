using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_2
{
    public class Program
    {
        public static List<int> Filter(List<int> list, Func<int, bool> function)
        {
            List<int> newList = new List<int>();
            for (int i = 0; i < list.Count; ++i)
                if (function(list[i]))
                    newList.Add(list[i]);
            return newList;
        }

        static void Main(string[] args)
        {
        }
    }
}
