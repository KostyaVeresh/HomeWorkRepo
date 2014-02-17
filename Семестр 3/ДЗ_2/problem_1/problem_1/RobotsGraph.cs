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
            bool tmp = false;

            for (int i = 0; i < robotCoordinates.Length; ++i)
            {
                for (int j = 0; j < robotCoordinates.Length; ++j)
                {
                    if (WayExists(robotCoordinates[i], robotCoordinates[j]))
                        tmp = true;
                }
                if (!tmp)
                {
                    Result = false;
                    return;
                }
                tmp = false;
            }
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

        private bool WayExists(int first, int second)
        {
            if (newMatrix[first, second] == 1)
                return true;
            visitedVertices[first] = true;
            for (int i = 0; i < adjacencyMatrix.GetLength(0); ++i)
                if ((newMatrix[first, i] != 0) && (!visitedVertices[i]))
                {
                    if (WayExists(i, second))
                        return true;
                }
            return false;
        }
    }
}
