using System;

namespace problem_1
{
    public class CountTree
    {
        private OperTree.TreeNode operRoot;

        public CountTree(OperTree tree)
        {
            operRoot = tree.Root;
        }
        
        private int countResult(OperTree.TreeNode node)
        {
            int result = 0;
            if ((node.Left == null) && (node.Right == null))
                result = node.Value - '0';
            else
                result = Operations.Operation((char)node.Value, countResult(node.Left), countResult(node.Right));
            return result;
        }

        /// <summary>
        /// Counts the result of arithmetical expression by its operation tree.
        /// </summary>
        /// <returns></returns>
        public int countResult()
        {
            return countResult(operRoot);
        }
    }
}
