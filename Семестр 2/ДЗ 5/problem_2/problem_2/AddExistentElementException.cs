using System;

namespace problem_2
{
    public class AddExistentElementException : ApplicationException
    {
        public AddExistentElementException()
        {
        }

        public AddExistentElementException(string message)
            : base(message)
        {
        }
    }
}
