using System;

namespace problem_2
{
    public class List
    {
        public class ListElement
        {
            private int number;
            private ListElement next;
            public int Number
            {
                get 
                {
                    return number; 
                }
                set
                {
                    number = value;
                }
            }
            public ListElement Next
            {
                get
                {
                    return next;
                }
                set
                {
                    next = value;
                }
            }
        }
        private ListElement head;
        public ListElement Head
        {
            get
            {
                return head;
            }
            private set
            {
                head = value;
            }
        }

        public List()
        {
            Head = new ListElement();
            Head.Next = null;
            Head.Number = 0;
        }

        public int SizeOfList()
        {
            int size = 0;
            ListElement tmp = head.Next;
            while (tmp != null)
            {
                ++size;
                tmp = tmp.Next;
            }
            return size;
        }

        public ListElement ElemPos(int value)
        {
            ListElement tmp = head;
            while (tmp.Number != value)
                tmp = tmp.Next;
            return tmp;
        }

        public void AddElem(ListElement pos, int value)
        {
	        ListElement tmp = new ListElement();
	        tmp.Number = value;
	        tmp.Next = pos.Next;
	        pos.Next = tmp;
        }

        public void DeleteElem(int value)
        {
            ListElement tmp = head;
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
            ListElement tmp = head;
            while (tmp.Next != null)
            {
                Console.Write("{0} ", tmp.Next.Number);
                tmp = tmp.Next;
            }
            Console.WriteLine();
        }
    }
}
