using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_2.Test
{
    [TestClass]
    public class ListTest
    {
        private List list;

        [TestInitialize]
        public void Initialize()
        {
            list = new List();
            list.AddElem(1);
            list.AddElem(2);
            list.AddElem(3);
        }

        [TestMethod]
        public void AddElemTest()
        {
            var tmp = list.Head.Next;
            Assert.IsTrue(tmp.Number == 1);
            Assert.IsTrue(tmp.Next.Number == 2);
        }

        [TestMethod]
        public void DeleteElemTest()
        {
            list.DeleteElem(2);
            var tmp = list.Head.Next;
            Assert.IsTrue(tmp.Next.Number == 3);
        }
    }
}
