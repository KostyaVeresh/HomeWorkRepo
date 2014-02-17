using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_2
{
    public class Network
    {
        private int[,] adjacencyMatrix;
        public Computer[] ComputersOfNet { get; private set; }

        public Network(int[,] adjacencyMatrix, char[] computerOs, bool[] virusedComputers)
        {
            this.adjacencyMatrix = adjacencyMatrix;
            this.ComputersOfNet = new Computer[computerOs.Length];
            for (int i = 0; i < computerOs.Length; ++i)
                ComputersOfNet[i] = new Computer(computerOs[i], virusedComputers[i]);
        }

        private bool[] tryToInfect()
        {
            bool[] canBeVirused = new bool[ComputersOfNet.Length];
            for (int i = 0; i < ComputersOfNet.Length; ++i)
            {
                canBeVirused[i] = false;
            }
            for (int i = 0; i < ComputersOfNet.Length; ++i)
            {
                if (ComputersOfNet[i].IsVirused)
                {
                    for (int j = 0; j < ComputersOfNet.Length; ++j)
                    {
                        if (adjacencyMatrix[i, j] == 1)
                        {
                            canBeVirused[j] = true;
                        }
                    }
                }
            }
            return canBeVirused;
        }

        public void NextState(int value)
        {
            for (int i = 0; i < ComputersOfNet.Length; ++i)
                if (tryToInfect()[i])
                    ComputersOfNet[i].Infect(value);
        }

        public void NextState()
        {
            for (int i = 0; i < ComputersOfNet.Length; ++i)
                if (tryToInfect()[i])
                    ComputersOfNet[i].Infect();
        }
    }
}
