using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem.Test
{
    [TestClass]
    public class BubbleSortTest
    {
        [TestMethod]
        public void BubbleSortTest1()
        {
            int[] mas = new int[] { 1, 5, 8, 3, 9 };
            Program.BubbleSort<int>(ref mas, mas.Length, new Comparator<int>());
            Assert.IsTrue(mas[0] == 1 && mas[1] == 3 && mas[2] == 5 && mas[3] == 8 && mas[4] == 9);
        }

        [TestMethod]
        public void BubbleSortTest2()
        {
            char[] mas = new char[] { 'f', 'a', 'e', 'b' };
            Program.BubbleSort<char>(ref mas, mas.Length, new Comparator<char>());
            Assert.IsTrue(mas[0] == 'a' && mas[1] == 'b' && mas[2] == 'e' && mas[3] == 'f');
        }
    }
}
