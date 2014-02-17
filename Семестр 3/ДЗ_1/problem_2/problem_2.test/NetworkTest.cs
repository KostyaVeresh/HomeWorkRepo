using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_2.test
{
    [TestClass]
    public class NetworkTest
    {
        private Network net;

        [TestInitialize]
        public void Initialize()
        {
            int[,] adMatrix = { {0, 1, 0, 0, 1, 0 }
                              , {1, 0, 1, 0, 1, 0 }
                              , {0, 1, 0, 1, 0, 0 }
                              , {0, 0, 1, 0, 1, 1 }
                              , {1, 1, 0, 1, 0, 0 }
                              , {0, 0, 0, 1, 0, 0 } 
                              };
            char[] os = {'w', 'w', 'l', 'm', 'm', 'l'};
            bool[] virused = {false, false, false, false, false, true};
            net = new Network(adMatrix, os, virused);
        }

        [TestMethod]
        public void NextStateTest()
        {
            net.NextState(45);
            Assert.IsFalse(net.ComputersOfNet[3].IsVirused);
            net.NextState(35);
            Assert.IsTrue(net.ComputersOfNet[3].IsVirused);
            net.NextState(35);
            Assert.IsTrue(net.ComputersOfNet[4].IsVirused);
            Assert.IsFalse(net.ComputersOfNet[2].IsVirused);
        }
    }
}
