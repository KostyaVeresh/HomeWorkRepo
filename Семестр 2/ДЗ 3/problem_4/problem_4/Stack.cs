using System;

namespace problem_4
{
    /// <summary>
    /// Stack of int elements.
    /// </summary>
    public interface Stack
    {
        /// <summary>
        /// Returns true if there are no elements in the stack.
        /// </summary>
        bool IsEmpty();

        /// <summary>
        /// Pushes new element to the stack.
        /// </summary>
        /// <param name="num"></param>
        void Push(int num);

        /// <summary>
        /// Returns the top element of stack;
        /// </summary>
        int Top();

        /// <summary>
        /// Pops the element from the top of stack.
        /// </summary>
        int Pop();
        
        /// <summary>
        /// Prints elements of the stack in order from top to end. 
        /// </summary>
        void PrintStack();
    }
}
