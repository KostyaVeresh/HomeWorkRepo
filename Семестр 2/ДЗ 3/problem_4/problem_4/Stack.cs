using System;

namespace problem_4
{
    public interface Stack
    {
        bool IsEmpty();
        void Push(int num);
        int Top();
        int Pop();
        void PrintStack();
    }
}
