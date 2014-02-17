using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_2.test
{
    [TestClass]
    public class ProgramTest
    {
        [TestMethod]
        public void ZeroElementsTest()
        {
            int[] arr = { 2, 0, 5, 3, 2, 0 };
            Assert.AreEqual(Program.zeroElements(arr), 2);
            arr[2] = 0;
            Assert.AreEqual(Program.zeroElements(arr), 3);
        }
    }
}
