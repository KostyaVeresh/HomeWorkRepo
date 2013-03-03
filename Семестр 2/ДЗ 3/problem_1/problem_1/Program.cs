using System;

namespace problem_1
{
    class StackElement
    {
        public int value;
        public StackElement next;
    }

    class Stack
    {
        public StackElement head;

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
            StackElement tmp = head;
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

    class Program
    {
        static void Main(string[] args)
        {
            Stack stack = new Stack();
            for (int i = 1; i <= 5; ++i)
            {
                stack.Push(i);
            }
            stack.printStack();
            Console.WriteLine("The top of stack: {0}", stack.Top());
            Console.ReadLine();
        }
    }
}
