using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_4.Test
{
    [TestClass]
    public class StackOnListTest
    {
        private Stack stack;

        [TestInitialize]
        public void Initialize()
        {
            stack = new StackOnList();
        }

        [TestMethod]
        public void IsEmptyTest()
        {
            Assert.IsTrue(stack.IsEmpty());
            stack.Push(3);
            Assert.IsFalse(stack.IsEmpty());
        }

        [TestMethod]
        public void PushTest()
        {
            stack.Push(3);
            Assert.AreEqual(3, stack.Top());
            stack.Push(4);
            Assert.AreEqual(4, stack.Top());
        }

        [TestMethod]
        [ExpectedException(typeof(System.Exception))]
        public void TopOfEmptyStack()
        {
            stack.Top();
        }

        [TestMethod]
        public void PopTest()
        {
            stack.Push(3);
            stack.Push(4);
            Assert.AreEqual(4, stack.Pop());
            Assert.AreEqual(3, stack.Top());
        }

        [TestMethod]
        [ExpectedException(typeof(System.Exception))]
        public void PopInEmptyStack()
        {
            stack.Pop();
        }
    }
}
