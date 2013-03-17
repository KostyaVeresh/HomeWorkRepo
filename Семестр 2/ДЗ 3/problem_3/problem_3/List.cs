using System;

namespace problem_3
{
    public class List
    {
        public class ListElement
        {
            public string Str { get; set; }
            public int Count { get; set; }
            public ListElement Next { get; set; }
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
            Head.Str = "";
            Head.Count = 0;
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

        public bool IsEmpty()
        {
            return head.Next == null;
        }

        public ListElement ElemPos(string value)
        {
            ListElement tmp = head;
            while (tmp.Str != value)
                tmp = tmp.Next;
            return tmp;
        }

        public void AddElem(ListElement pos, string value)
        {
	        ListElement tmp = new ListElement();
	        tmp.Str = value;
	        tmp.Next = pos.Next;
	        pos.Next = tmp;
        }

        public void DeleteElem(string value)
        {
            ListElement tmp = head;
            while (tmp.Next.Str != value)
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
                Console.WriteLine(tmp.Next.Str + " " + tmp.Next.Count);
                tmp = tmp.Next;
            }
            Console.WriteLine();
        }
    }
}