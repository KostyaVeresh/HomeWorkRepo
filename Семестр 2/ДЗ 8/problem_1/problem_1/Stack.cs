using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_1
{
    public class Stack<T>
    {
        private class StackElement<T>
        {
            public T value;
            public StackElement<T> next;
        }
        private StackElement<T> head;

        public Stack()
        {
            head = null;
        }

        public bool IsEmpty()
        {
            return head == null;
        }

        public void Push(T num)
        {
            StackElement<T> temp = new StackElement<T>();
            temp.value = num;
            temp.next = head;
            head = temp;
        }

        public T Top()
        {
            if (IsEmpty())
                throw new Exception("The stack is empty");
            return head.value;
        }

        public T Pop()
        {
            T result = Top();
            head = head.next;
            return result;
        }

        public void printStack()
        {
            StackElement<T> tmp = head;
            while (tmp != null)
            {
                Console.Write("{0} ", tmp.value);
                tmp = tmp.next;
            }
            Console.WriteLine();
        }
    }
}
