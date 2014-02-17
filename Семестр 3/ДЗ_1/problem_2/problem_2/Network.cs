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

        /// <summary>
        /// Creates net of computers and sets OS and viruses
        /// </summary>
        /// <param name="adjacencyMatrix"></param>
        /// <param name="computerOs"></param>
        /// <param name="virusedComputers"></param>
        public Network(int[,] adjacencyMatrix, char[] computerOs, bool[] virusedComputers)
        {
            this.adjacencyMatrix = adjacencyMatrix;
            this.ComputersOfNet = new Computer[computerOs.Length];
            for (int i = 0; i < computerOs.Length; ++i)
                ComputersOfNet[i] = new Computer(computerOs[i], virusedComputers[i]);
        }

        /// <summary>
        /// Returns if some computers can be virused
        /// </summary>
        /// <returns></returns>
        private bool[] TryToInfect()
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

        /// <summary>
        /// Takes int parameter and sets the system to the next state after infection
        /// </summary>
        /// <param name="value"></param>
        public void NextState(int value)
        {
            for (int i = 0; i < ComputersOfNet.Length; ++i)
                if (TryToInfect()[i])
                    ComputersOfNet[i].Infect(value);
        }

        /// <summary>
        /// Sets the system to the next state after infection
        /// </summary>
        public void NextState()
        {
            for (int i = 0; i < ComputersOfNet.Length; ++i)
                if (TryToInfect()[i])
                    ComputersOfNet[i].Infect();
        }
    }
}
