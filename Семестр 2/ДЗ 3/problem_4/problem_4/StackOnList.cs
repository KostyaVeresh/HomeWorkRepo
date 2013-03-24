using System;

namespace problem_4
{
    public class StackOnList : Stack
    {
        private class StackElement
        {
            public int value;
            public StackElement next;
        }

        private StackElement head;

        public StackOnList()
        {
            head = null;
        }

        public bool IsEmpty()
        {
            return head == null;
        }

        public void Push(int num)
        {
            StackElement temp = new StackElement();
            temp.value = num;
            temp.next = head;
            head = temp;
        }

        public int Top()
        {
            if (!IsEmpty())
                return head.value;
            else
                return 0;
        }

        public int Pop()
        {
            int result = Top();
            if (!IsEmpty())
                head = head.next;
            return result;
        }

        public void PrintStack()
        {
            StackElement tmp = head;
            while (tmp != null)
            {
                Console.Write("{0} ", tmp.value);
                tmp = tmp.next;
            }
            Console.WriteLine();
        }
    }
}
