using System;

namespace problem_2
{
    public class DeleteNonexistentElementException : ApplicationException
    {
        public DeleteNonexistentElementException()
        {
        }

        public DeleteNonexistentElementException(string message)
            : base(message)
        {
        }
    }
}
