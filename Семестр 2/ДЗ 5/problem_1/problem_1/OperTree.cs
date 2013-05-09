using System;

namespace problem_1
{
    public class OperTree : BinSearchTree 
    {
        private int MakeOperTree(TreeNode node, string str, int pos)
        {
            char sym = str[pos];
            if (sym == ' ' || sym == '(' || sym == ')')
            {
                ++pos;
                return MakeOperTree(node, str, pos);
            }
            else
            {
                AddElem(node, sym);
                ++pos;
                if (Operations.IsOper(sym))
                {
                    pos = MakeOperTree(node.Left, str, pos);
                    pos = MakeOperTree(node.Right, str, pos);
                }
                return pos;
            }
        }

        /// <summary>
        /// Creates tree of arithmetical expression.
        /// </summary>
        /// <param name="str"></param>
        public void MakeOperTree(string str)
        {
            MakeOperTree(Root, str, 0);
        }

        protected void PrintOperTree(TreeNode node)
        {
            Console.Write("{0} ", node.Value);
            if (node.Left != null)
                if (Operations.IsOper((char)node.Left.Value))
                    PrintOperTree(node.Left);
                else
                    Console.Write("{0} ", node.Left.Value);
            if (node.Right != null)
                if (Operations.IsOper((char)node.Right.Value))
                    PrintOperTree(node.Right);
                else
                    Console.Write("{0} ", node.Right.Value);
        }

        /// <summary>
        /// Prints the expression in the postfix form.
        /// </summary>
        public void PrintOperTree()
        {
            PrintOperTree(Root);
        }
    }
}
