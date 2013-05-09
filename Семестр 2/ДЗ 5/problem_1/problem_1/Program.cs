using System;

namespace problem_1
{
    class Program
    {
        static void Main(string[] args)
        {
            var u = new BinSearchTree();
            u.AddElem(5);
            u.AddElem(3);
            u.PrintInOrder();
            Console.ReadLine();
        }
    }
}
