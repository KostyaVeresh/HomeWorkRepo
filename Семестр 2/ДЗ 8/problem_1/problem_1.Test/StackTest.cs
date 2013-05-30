using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_1.Test
{
    [TestClass]
    public class StackTest
    {
        private Stack<int> stack;

        [TestInitialize]
        public void Initialize()
        {
            stack = new Stack<int>();
            stack.Push(1);
            stack.Push(2);
            stack.Push(3);
        }

        [TestMethod]
        public void PushTest()
        {
            Assert.IsTrue(stack.Top() == 3);
            stack.Push(5);
            Assert.IsTrue(stack.Top() == 5);
        }

        [TestMethod]
        public void PopTest()
        {
            Assert.IsTrue(stack.Pop() == 3);
            Assert.IsTrue(stack.Pop() == 2);
        }
    }
}
