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
            list.AddElem(list.Head, 4);
            list.AddElem(list.Head.Next, 5);
            list.AddElem(list.Head, 1);
        }

        [TestMethod]
        public void SizeOfListTest()
        {
            Assert.AreEqual(3, list.SizeOfList());
        }

        [TestMethod]
        public void AddElemTest()
        {
            var elem = list.Head.Next;
            Assert.AreEqual(1, elem.Number);
            Assert.AreEqual(4, elem.Next.Number);
            Assert.AreEqual(5, elem.Next.Next.Number);
        }

        [TestMethod]
        public void DeleteElemTest()
        {
            list.DeleteElem(4);
            var elem = list.Head.Next;
            Assert.AreEqual(5, elem.Next.Number);
            Assert.AreEqual(null, elem.Next.Next);
            list.DeleteElem(1);
            Assert.AreEqual(5, list.Head.Next.Number);
        }

        [TestMethod]
        public void DeleteNonexistentElementTest()
        {
            int num = list.SizeOfList();
            list.DeleteElem(8);
            Assert.AreEqual(list.SizeOfList(), num);
        }
    }
    
}
