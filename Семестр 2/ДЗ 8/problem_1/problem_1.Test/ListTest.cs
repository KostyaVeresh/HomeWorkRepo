using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_1.Test
{
    [TestClass]
    public class ListTest
    {
        private List<int> list;

        [TestInitialize]
        public void Initialize()
        {
            list = new List<int>();
            list.AddElem(1);
            list.AddElem(2);
            list.AddElem(3);
        }

        [TestMethod]
        public void AddElemTest()
        {
            var tmp = list.Head.Next;
            Assert.IsTrue(tmp.Value == 1);
            Assert.IsTrue(tmp.Next.Value == 2);
        }

        [TestMethod]
        public void DeleteElemTest()
        {
            list.DeleteElem(2);
            var tmp = list.Head.Next;
            Assert.IsTrue(tmp.Next.Value == 3);
        }

        [TestMethod]
        public void ForeachTest()
        {
            int[] mas = new int[3];
            int i = 0;
            foreach (int x in list)
            {
                mas[i] = x;
                ++i;
            }
            Assert.IsTrue(mas[0] == 1);
            Assert.IsTrue(mas[1] == 2);
            Assert.IsTrue(mas[2] == 3);
        }
    }
}
