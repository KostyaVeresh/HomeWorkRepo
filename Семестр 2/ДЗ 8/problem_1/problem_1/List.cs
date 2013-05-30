using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_1
{
    public class List<T> : IEnumerable<T>
    {
        public ListElement<T> Head { get; set; }

        public List()
        {
            Head = new ListElement<T>();
            Head.Next = null;
            Head.Value = default(T);
        }

        public int SizeOfList()
        {
            int size = 0;
            ListElement<T> tmp = Head.Next;
            while (tmp != null)
            {
                ++size;
                tmp = tmp.Next;
            }
            return size;
        }

        public ListElement<T> First
        {
            get
            {
                return this.Head;
            }
        }

        public ListElement<T> ElemPos(T value)
        {
            ListElement<T> tmp = Head;
            while (!tmp.Value.Equals(value))
                tmp = tmp.Next;
            return tmp;
        }

        public void AddElem(ListElement<T> pos, T value)
        {
	        ListElement<T> tmp = new ListElement<T>();
	        tmp.Value = value;
	        tmp.Next = pos.Next;
	        pos.Next = tmp;
        }

        public void AddElem(T value)
        {
            var tmp = Head;
            while (tmp.Next != null)
                tmp = tmp.Next;
            AddElem(tmp, value);
        }

        public void DeleteElem(T value)
        {
            ListElement<T> tmp = Head;
            while (!tmp.Next.Value.Equals(value))
            {
                tmp = tmp.Next;
                if (tmp.Next == null)
                    break;
            }
            if (tmp.Next != null)
            {
                ListElement<T> tmp1 = ElemPos(value);
                tmp.Next = tmp1.Next;  
            }          
        }

        public void PrintList()
        {
            ListElement<T> tmp = Head;
            while (tmp.Next != null)
            {
                Console.Write("{0} ", tmp.Next.Value);
                tmp = tmp.Next;
            }
            Console.WriteLine();
        }

        public IEnumerator<T> GetEnumerator()
        {
            return new ListIterator<T>(this);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }
    }
}
