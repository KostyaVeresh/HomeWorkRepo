using System;

namespace problem_4
{
    public class StackOnArray : Stack
    {
        private int[] stack;

        public StackOnArray(int maxNumber)
        {
            stack = new int[maxNumber];
        }

        private int ElemNullIndex()
        {
            if (!IsEmpty())
            {
                int ind = 0;
                while (stack[ind] != 0)
                    ++ind;
                return ind;
            }
            else
                return 1;
        }

        public bool IsEmpty()
        {
            return stack[0] == 0;
        }

        public void Push(int num)
        {
            if (!IsEmpty())
                stack[ElemNullIndex()] = num;
            else
                stack[0] = num;
        }

        public int Top()
        {
            return stack[ElemNullIndex() - 1];
        }

        public int Pop()
        {
            int result = Top();
            stack[ElemNullIndex() - 1] = 0;
            return result;
        }

        public void PrintStack()
        {
            for (int i = ElemNullIndex() - 1; i >= 0; --i)
                Console.Write("{0} ", stack[i]);
        }
    }
}
