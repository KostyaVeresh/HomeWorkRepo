using System;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_2.Test
{
    [TestClass]
    public class ProgramTest
    {
        [TestMethod]
        public void FilterTest()
        {
            List<int> list = Program.Filter(new List<int>(){6, 2, 4, 8, 5, 10, 3, 1, 7}, x => x > 5);
            Assert.IsTrue(list[0] == 6 && list[1] == 8 && list[2] == 10 && list[3] == 7);
        }
    }
}
