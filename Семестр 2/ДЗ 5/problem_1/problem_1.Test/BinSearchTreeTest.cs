using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_1.Test
{
    [TestClass]
    public class BinSearchTreeTest
    {
        private BinSearchTree binTree;

        [TestInitialize]
        public void Initialize()
        {
            binTree = new BinSearchTree();
            binTree.AddElem(1);
            binTree.AddElem(3);
            binTree.AddElem(8);
        }

        [TestMethod]
        public void ExistsTest()
        {
            Assert.IsTrue(binTree.Exists(3) && binTree.Exists(8));
            Assert.IsFalse(binTree.Exists(10));
        }


    }
}
