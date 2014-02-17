using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_1
{
    public class RobotsGraph
    {
        private int[,] adjacencyMatrix;
        private bool[] visitedVertices;
        private int[,] newMatrix;
        public bool Result { get; private set; }

        /// <summary>
        /// Creates matrix of robots' way and gives a result if they are exploded
        /// </summary>
        /// <param name="adMatrix"></param>
        /// <param name="robotCoordinates"></param>
        public RobotsGraph(int[,] adMatrix, int[] robotCoordinates)
        {
            this.adjacencyMatrix = adMatrix;
            this.newMatrix = new int[adjacencyMatrix.GetLength(0),adjacencyMatrix.GetLength(0)];
            this.visitedVertices = new bool[adjacencyMatrix.GetLength(0)];
            for (int i = 0; i < adjacencyMatrix.GetLength(0); ++i)
                visitedVertices[i] = false;
            CreateNewMatrix(0);
            int count1 = 0;

            for (int i = 0; i < adjacencyMatrix.GetLength(0); ++i)
            {
                for (int j = 0; j < adjacencyMatrix.GetLength(0); ++j)
                {
                    if (newMatrix[i, j] == 1)
                    {
                        bool tmp = false;
                        for (int k = 0; k < robotCoordinates.Length; ++k)
                            if (robotCoordinates[k] == i || robotCoordinates[k] == j)
                                tmp = true;
                        if (tmp)
                            ++count1;
                    }
                }
            }
            count1 = count1 / 2;
            int count2 = robotCoordinates.Length - count1;
            Result = (count1 != 1) && (count2 != 1);
        }

        /// <summary>
        /// Creates matrix of "over-one" connection
        /// </summary>
        /// <param name="index"></param>
        private void CreateNewMatrix(int index)
        {
            visitedVertices[index] = true;
            for (int i = 0; i < adjacencyMatrix.GetLength(0); ++i)
                if ((adjacencyMatrix[index, i] != 0) && (!visitedVertices[i]))
                {
                    visitedVertices[i] = true;
                    for (int j = 0; j < adjacencyMatrix.GetLength(0); ++j)
                    {
                        if ((adjacencyMatrix[i, j] != 0) && (!visitedVertices[j]))
                        {
                            newMatrix[index, j] = 1;
                            newMatrix[j, index] = 1;
                            CreateNewMatrix(j);
                        }
                    }
                }
            for (int i = 0; i < adjacencyMatrix.GetLength(0); ++i)
                visitedVertices[i] = false;
        }
    }
}
