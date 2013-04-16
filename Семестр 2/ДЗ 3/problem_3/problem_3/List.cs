using System;

namespace problem_3
{
    /// <summary>
    /// Singly linked list of pairs of values.
    /// </summary>
    public class List
    {
        /// <summary>
        /// Element of list consists of string and number.
        /// </summary>
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

        /// <summary>
        /// Creates the head of list.
        /// </summary>
        public List()
        {
            Head = new ListElement();
            Head.Next = null;
            Head.Str = "";
            Head.Count = 0;
        }

        /// <summary>
        /// Returns number of elements of the list.
        /// </summary>
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

        /// <summary>
        /// Returns true if there are no elements in the list.
        /// </summary>
        public bool IsEmpty()
        {
            return head.Next == null;
        }

        /// <summary>
        /// Returns the position of the element
        /// </summary>
        /// <param name="value"></param>
        public ListElement ElemPos(string value)
        {
            ListElement tmp = head;
            while (tmp.Str != value)
                tmp = tmp.Next;
            return tmp;
        }

        /// <summary>
        /// Adds new element to the list
        /// </summary>
        /// <param name="pos"></param>
        /// <param name="value"></param>
        public void AddElem(ListElement pos, string value)
        {
	        ListElement tmp = new ListElement();
	        tmp.Str = value;
	        tmp.Next = pos.Next;
	        pos.Next = tmp;
        }

        /// <summary>
        /// Deletes element from the list.
        /// </summary>
        /// <param name="value"></param>
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
            else
                throw new Exception("Can't find the element in the list.");
        }

        /// <summary>
        /// Prints elements from the first element to the end of list.
        /// </summary>
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