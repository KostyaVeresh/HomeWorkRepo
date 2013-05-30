using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_2.Test
{
    [TestClass]
    public class SetTest
    {
        private Set<int> set;

        [TestInitialize]
        public void Initialize()
        {
            set = new Set<int>();
            set.AddElem(4);
            set.AddElem(3);
            set.AddElem(3);
            set.AddElem(5);
        }

        [TestMethod]
        public void AddElemTest()
        {
            Assert.IsTrue(set.Exists(4));
            Assert.IsTrue(set.Exists(5));
            Assert.IsTrue(set.Exists(3));
            Assert.IsFalse(set.Exists(2));
        }

        [TestMethod]
        public void DeleteElemTest()
        {
            set.deleteElem(3);
            set.deleteElem(2);
            set.deleteElem(4);
            Assert.IsTrue(set.Exists(5));
            Assert.IsFalse(set.Exists(3) || set.Exists(2));
        }

        [TestMethod]
        public void UnionTest()
        {
            var newSet = new Set<int>();
            newSet.AddElem(7);
            newSet.AddElem(8);
            newSet.AddElem(9);
            var unionSet = set.Union(newSet);
            Assert.IsTrue(unionSet.Exists(3) && unionSet.Exists(4));
            Assert.IsTrue(unionSet.Exists(7) && unionSet.Exists(8));
        }

        [TestMethod]
        public void IntersectionTest()
        {
            var newSet = new Set<int>();
            newSet.AddElem(4);
            newSet.AddElem(5);
            newSet.AddElem(10);
            var intersection = set.Intersection(newSet);
            Assert.IsTrue(intersection.Exists(4) && intersection.Exists(5));
            Assert.IsFalse(intersection.Exists(3) || intersection.Exists(10));
        }
    }
}
