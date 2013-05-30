using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_1
{
    public class ListElement<T>
    {
        public T Value { get; set; }
        public ListElement<T> Next { get; set; }
    }
}
