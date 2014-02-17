using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_1.test
{
    [TestClass]
    public class BinaryTreeTest
    {
        private BinaryTree tree;

        [TestInitialize]
        public void Initialize()
        {
            tree = new BinaryTree();
            tree.AddElem(3);
            tree.AddElem(4);
            tree.AddElem(1);
            tree.AddElem(5);
        }

        [TestMethod]
        public void AddElemTest()
        {
            int[] mas = {1, 3, 4, 5};
            int num = 0;
            foreach (int value in tree)
            {
                Assert.AreEqual(mas[num], value);
                ++num;
            }
        }

        [TestMethod]
        public void DeleteElemTest()
        {
            int[] mas = { 1, 4 };
            int num = 0;
            tree.DeleteElem(5);
            tree.DeleteElem(3);
            foreach(int value in tree)
            {
                Assert.AreEqual(mas[num], value);
                ++num;
            }
        }
    }
}
