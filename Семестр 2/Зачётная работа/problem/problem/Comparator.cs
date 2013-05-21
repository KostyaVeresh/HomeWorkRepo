using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem
{
    /// <summary>
    ///  compares variables witf type-parameter
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public class Comparator<T>
    {
        /// <summary>
        /// takes two variables, returns the compare result
        /// </summary>
        /// <param name="first"></param>
        /// <param name="second"></param>
        /// <returns></returns>
        public bool Compare(T first, T second)
        {
            int number1 = first.GetHashCode();
            int number2 = second.GetHashCode();
            return number1 > number2;
        }
    }
}
