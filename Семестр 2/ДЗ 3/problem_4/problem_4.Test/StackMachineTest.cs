using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_4.Test
{
    [TestClass]
    public class StackMachineTest
    {
        private Stack stack;

        [TestInitialize]
        public void Initialize()
        {
            stack = new StackOnList();
        }

        [TestMethod]
        public void CountExpressionTest()
        {
            string str = "9 6 - 1 2 + *";
            Program.StackMachine(stack, str);
            Assert.AreEqual(9, stack.Top());
        }

        [TestMethod]
        [ExpectedException(typeof(System.Exception))]
        public void DevidingByZeroTest()
        {
            string str = "3 0 /";
            Program.StackMachine(stack, str);
        }
    }
}
