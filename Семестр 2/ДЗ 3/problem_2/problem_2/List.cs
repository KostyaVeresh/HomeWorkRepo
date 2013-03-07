using System;

namespace problem_2
{
    class List
    {
        private class ListElement
        {
            public int value;
            public ListElement next;
        }
        private ListElement head;

        public List()
        {
            head.next = null;
            head.value = 0;
        }

        public ListElement elemPos(int value)
        {
            ListElement tmp = head;
            while (tmp.value != value)
                tmp = tmp.next;
            return tmp;
        }

        public void addElem(ListElement pos, int value)
        {
	        ListElement tmp = new ListElement();
	        tmp.value = value;
	        tmp.next = pos.next;
	        pos.next = tmp;
        }

        public void deleteElem(int value)
        {
            ListElement tmp = head;
            while (tmp.next.value != value)
                tmp = tmp.next;
            ListElement tmp1 = elemPos(value);
            tmp.next = tmp1.next;  
        }

        public void printList()
        {
            ListElement tmp = head;
            while (tmp.next != null)
            {
                Console.Write("{0} ", tmp.next.value);
                tmp = tmp.next;
            }
            Console.WriteLine();
        }
    }
}
