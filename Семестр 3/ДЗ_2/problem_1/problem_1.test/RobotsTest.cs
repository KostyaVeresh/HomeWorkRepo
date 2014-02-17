using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_1.test
{
    [TestClass]
    public class RobotsTest
    {
        [TestMethod]
        public void RobotsGraphTest()
        {
            int[,] adMatrix = { {0, 1, 0, 0}
                              , {1, 0, 1, 0}
                              , {0, 1, 0, 1}
                              , {0, 0, 1, 0}
                              };
            int[] robots = { 0, 3 };
            RobotsGraph gr = new RobotsGraph(adMatrix, robots);
            Assert.IsFalse(gr.Result);
        }
    }
}
