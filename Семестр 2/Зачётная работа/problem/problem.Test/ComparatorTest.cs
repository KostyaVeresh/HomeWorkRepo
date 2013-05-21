using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem.Test
{
    [TestClass]
    public class ComparatorTest
    {
        [TestMethod]
        public void CompareTest1()
        {
            Assert.IsTrue(new Comparator<int>().Compare(2, 1));
            Assert.IsFalse(new Comparator<int>().Compare(1, 2));
        }

        [TestMethod]
        public void CompareTest2()
        {
            Assert.IsTrue(new Comparator<int>().Compare('b', 'a'));
            Assert.IsFalse(new Comparator<int>().Compare('a', 'b'));
        }
    }
}
