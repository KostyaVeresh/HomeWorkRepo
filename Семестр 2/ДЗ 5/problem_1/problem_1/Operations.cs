using System;

namespace problem_1
{
    public class Operations
    {
        /// <summary>
        /// Takes symbol and returns true if it is symbol of operation.
        /// </summary>
        /// <param name="symbol"></param>
        public static bool IsOper(char symbol)
        {
            return (symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/');
        }

        /// <summary>
        /// Takes the symbol of operation and operadns. Returns the result of operation.
        /// </summary>
        /// <param name="oper"></param>
        /// <param name="first"></param>
        /// <param name="second"></param>
        public static int Operation(char oper, int first, int second)
        {
            if (oper == '+')
                return (first + second);
            if (oper == '-')
                return (first - second);
            if (oper == '*')
                return (first * second);
            if (oper == '/')
                if (second == 0)
                    throw new Exception("Sorry, but you can't devide by zero");
                else
                    return (first / second);
            return 0;
        }
    }
}
