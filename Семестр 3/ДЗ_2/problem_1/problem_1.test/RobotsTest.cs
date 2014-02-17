using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_1.test
{
    [TestClass]
    public class RobotsTest
    {
        [TestMethod]
        public void RobotsGraphTest1()
        {
            int[,] adMatrix = { {0, 1, 0, 0, 0}
                              , {1, 0, 1, 0, 0}
                              , {0, 1, 0, 1, 0}
                              , {0, 0, 1, 0, 1}
                              , {0, 0, 0, 1, 0}
                              };
            int[] robots = { 0, 4 };
            RobotsGraph gr = new RobotsGraph(adMatrix, robots);
            Assert.IsTrue(gr.Result);
        }

        [TestMethod]
        public void RobotsGraphTest2()
        {
            int[,] adMatrix = { {0, 1, 0, 0, 0}
                              , {1, 0, 0, 1, 0}
                              , {0, 0, 0, 1, 0}
                              , {0, 1, 1, 0, 1}
                              , {0, 0, 0, 1, 0}
                              };
            int[] robots = { 0, 4 };
            RobotsGraph gr = new RobotsGraph(adMatrix, robots);
            Assert.IsFalse(gr.Result);

        }
    }
}
