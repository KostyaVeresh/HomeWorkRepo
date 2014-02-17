using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] adMatrix = { {0, 1, 0, 0, 0}
                              , {1, 0, 1, 0, 0}
                              , {0, 1, 0, 1, 0}
                              , {0, 0, 1, 0, 1}
                              , {0, 0, 0, 1, 0}
                              };
            int[] robots = { 0, 4 };
            RobotsGraph gr = new RobotsGraph(adMatrix, robots);
        }
    }
}
