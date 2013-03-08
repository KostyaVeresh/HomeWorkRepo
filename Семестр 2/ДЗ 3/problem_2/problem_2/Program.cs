using System;

namespace problem_2
{
    class Program
    {
        static void Main(string[] args)
        {
            List list = new List();
            list.addElem(list.head, 4);
            list.addElem(list.head, 10);
            list.addElem(list.head.next, 11);
            list.addElem(list.head.next, 12);
            list.printList();
            Console.ReadLine();
        }
    }
}
