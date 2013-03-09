using System;

namespace problem_2
{
    class Program
    {
        static void Main(string[] args)
        {
            List list = new List();
            list.AddElem(list.Head, 4);
            list.AddElem(list.Head, 10);
            list.AddElem(list.Head.Next, 11);
            list.AddElem(list.Head.Next, 12);
            list.PrintList();
            Console.ReadLine();
        }
    }
}
