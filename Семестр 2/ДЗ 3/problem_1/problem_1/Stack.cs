using System;

namespace problem_1
{
    class Stack
    {
        private class StackElement
        {
            public int value;
            public StackElement next;
        }
        private StackElement head;

        public Stack()
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
            return head.value;
        }

        public int Pop()
        {
            int result = Top();
            head = head.next;
            return result;
        }

        public void printStack()
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
