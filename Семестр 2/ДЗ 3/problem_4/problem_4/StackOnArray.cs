using System;

namespace problem_4
{
    /// <summary>
    /// Stack of int elements based on array.
    /// </summary>
    public class StackOnArray : Stack
    {
        private int[] stack;

        private int numOfElem;

        public StackOnArray(int maxNumber)
        {
            stack = new int[maxNumber];
            numOfElem = 0;
        }

        /// <summary>
        /// Returns true if there are no elements in the stack.
        /// </summary>
        public bool IsEmpty()
        {
            return numOfElem == 0;
        }

        /// <summary>
        /// Pushes new element to the stack.
        /// </summary>
        /// <param name="num"></param>
        public void Push(int num)
        {
            stack[numOfElem] = num;
            ++numOfElem;
        }

        /// <summary>
        /// Returns the top element of stack;
        /// </summary>
        public int Top()
        {
            if (!IsEmpty())
                return stack[numOfElem - 1];
            else
                throw new Exception("Stack is empty.");
        }

        /// <summary>
        /// Pops the element from the top of stack.
        /// </summary>
        public int Pop()
        {
            int result = Top();
            --numOfElem;
            return result;
        }

        /// <summary>
        /// Prints elements of the stack in order from top to end. 
        /// </summary>
        public void PrintStack()
        {
            for (int i = numOfElem - 1; i >= 0; --i)
                Console.Write("{0} ", stack[i]);
        }
    }
}
