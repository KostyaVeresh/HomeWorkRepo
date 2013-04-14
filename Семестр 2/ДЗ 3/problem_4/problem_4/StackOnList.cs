using System;

namespace problem_4
{
    /// <summary>
    /// Stack of int elements based on list.
    /// </summary>
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

        /// <summary>
        /// Returns true if there are no elements in the stack.
        /// </summary>
        public bool IsEmpty()
        {
            return head == null;
        }

        /// <summary>
        /// Pushes new element to the stack.
        /// </summary>
        /// <param name="num"></param>
        public void Push(int num)
        {
            StackElement temp = new StackElement();
            temp.value = num;
            temp.next = head;
            head = temp;
        }

        /// <summary>
        /// Returns the top element of stack;
        /// </summary>
        public int Top()
        {
            if (!IsEmpty())
                return head.value;
            else
                throw new Exception("Stack is empty.");
        }

        /// <summary>
        /// Pops the element from the top of stack.
        /// </summary>
        public int Pop()
        {
            int result = Top();
            if (!IsEmpty())
                head = head.next;
            return result;
        }

        /// <summary>
        /// Prints elements of the stack in order from top to end. 
        /// </summary>
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
