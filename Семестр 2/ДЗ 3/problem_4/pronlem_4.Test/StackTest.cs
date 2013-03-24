using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_4.Test
{
    [TestClass]
    public class StackTest
    {
        private Stack stack1;
        private Stack stack2;

        [TestInitialize]
        public void Initialize()
        {
            stack1 = new StackOnList();
            stack2 = new StackOnArray(100);
        }

        [TestMethod]
        public void IsEmptyTest()
        {
            Assert.IsTrue(stack1.IsEmpty());
            Assert.IsTrue(stack2.IsEmpty());
            stack1.Push(3);
            stack2.Push(3);
            Assert.IsFalse(stack1.IsEmpty());
            Assert.IsFalse(stack2.IsEmpty());
        }

        [TestMethod]
        public void PushTest()
        {
            stack1.Push(3);
            Assert.AreEqual(3, stack1.Top());
            stack1.Push(4);
            Assert.AreEqual(4, stack1.Top());
            stack2.Push(3);
            Assert.AreEqual(3, stack2.Top());
            stack2.Push(4);
            Assert.AreEqual(4, stack2.Top());
        }

        [TestMethod]
        public void TopOfEmptyStack()
        {
            Assert.AreEqual(0, stack1.Top());
            Assert.AreEqual(0, stack2.Top());
        }

        [TestMethod]
        public void PopTest()
        {
            stack1.Push(3);
            stack1.Push(4);
            stack2.Push(3);
            stack2.Push(4);
            Assert.AreEqual(4, stack1.Pop());
            Assert.AreEqual(3, stack1.Top());
            Assert.AreEqual(4, stack2.Pop());
            Assert.AreEqual(3, stack2.Top());
        }

        [TestMethod]
        public void PopInEmptyStack()
        {
            Assert.AreEqual(0, stack1.Pop());
            Assert.AreEqual(0, stack2.Pop());
        }
    }
}
