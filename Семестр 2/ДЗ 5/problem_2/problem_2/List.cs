using System;

namespace problem_2
{
    public class List
    {
        public class ListElement
        {
            public int Number { get; set; }
            public ListElement Next { get; set; }
        }
        public ListElement Head { get; set; }

        public List()
        {
            Head = new ListElement();
            Head.Next = null;
            Head.Number = 0;
        }

        public bool Exists(int elem)
        {
            var tmp = Head.Next;
            while (tmp != null)
            {
                if (tmp.Number == elem)
                {
                    return true;
                }
                tmp = tmp.Next;
            }
            return false;
        }

        public int SizeOfList()
        {
            int size = 0;
            ListElement tmp = Head.Next;
            while (tmp != null)
            {
                ++size;
                tmp = tmp.Next;
            }
            return size;
        }

        public ListElement ElemPos(int value)
        {
            ListElement tmp = Head;
            while (tmp.Number != value)
                tmp = tmp.Next;
            return tmp;
        }

        public virtual void AddElem(int elem)
        {
            var tmp = Head;
            while (tmp.Next != null)
                tmp = tmp.Next;
            AddElem(tmp, elem);
        }

        public void AddElem(ListElement pos, int value)
        {
	        ListElement tmp = new ListElement();
	        tmp.Number = value;
	        tmp.Next = pos.Next;
	        pos.Next = tmp;
        }

        public virtual void DeleteElem(int value)
        {
            ListElement tmp = Head;
            while (tmp.Next.Number != value)
            {
                tmp = tmp.Next;
                if (tmp.Next == null)
                    break;
            }
            if (tmp.Next != null)
            {
                ListElement tmp1 = ElemPos(value);
                tmp.Next = tmp1.Next;  
            }          
        }

        public void PrintList()
        {
            ListElement tmp = Head;
            while (tmp.Next != null)
            {
                Console.Write("{0} ", tmp.Next.Number);
                tmp = tmp.Next;
            }
            Console.WriteLine();
        }
    }
}
