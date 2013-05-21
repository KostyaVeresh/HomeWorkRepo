using System;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_1.Test
{
    [TestClass]
    public class ProgramTest
    {
        [TestMethod]
        public void MapTest()
        {
            List<int> list = Program.Map(new List<int>() { 1, 2, 3 }, x => x = x * 2);
            Assert.IsTrue(list[0] == 2 && list[1] == 4 && list[2] == 6);
        }
    }
}
