using System;

namespace problem_1
{
    public class BinSearchTree
    {
        public class TreeNode
        {
            public int Value { get; set; }
            public TreeNode Left { get; set; }
            public TreeNode Right { get; set; }

            public TreeNode(int value)
            {
                this.Value = value;
                this.Left = null;
                this.Right = null;
            }
        }

        public TreeNode Root { get; private set; }

        /// <summary>
        /// Creates empty tree.
        /// </summary>
        public BinSearchTree()
        {
            this.Root = null;
        }

        protected bool Exists(TreeNode node, int value)
        {
            if (node == null)
                return false;
            if (node.Value == value)
                return true;
            if (node.Value > value)
                return Exists(node.Left, value);
            else
                return Exists(node.Right, value);
        }

        /// <summary>
        /// Returns true if element exists in the tree.
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>
        public bool Exists(int value)
        {
            return Exists(Root, value);
        }

        protected void AddElem(TreeNode node, int value)
        {
            if (node == null)
            {
                node = new TreeNode(value);
            }
            else
                if (value < node.Value)
                    AddElem(node.Left, value);
                else
                    AddElem(node.Right, value);
        }

        /// <summary>
        /// Adds new element to the tree.
        /// </summary>
        /// <param name="value"></param>
        public void AddElem(int value)
        {
            AddElem(Root, value);
        }
  
        protected bool IsLeaf(TreeNode node)
        {
            return node.Right == null && node.Left == null;
        }

        protected bool HasOneChild(TreeNode node)
        {
            return node.Right == null && node.Left != null || node.Right != null && node.Left == null;
        }

        protected TreeNode MostLeftChild(TreeNode node)
        {
            if (node.Left != null)
                return MostLeftChild(node.Left);
            else
                return node;
        }

        protected void DeleteElem(TreeNode node, int value)
        {
            if (!Exists(node, value))
                throw new Exception("You can't delete nonexistent element.");
            if (node.Value > value)
                DeleteElem(node.Left, value);
            else if (node.Value < value)
                DeleteElem(node.Right, value);
            else if (IsLeaf(node))
            {
                node = null;
            }
            else if (HasOneChild(node))
            {
                if (node.Left != null)
                {
                    TreeNode tmp = node.Left;
                    node = tmp;
                }
                else if (node.Right != null)
                {
                    TreeNode tmp = node.Right;
                    node = tmp;
                }
            }
            else
            {
                TreeNode tmp = MostLeftChild(node.Right);
                node.Value = tmp.Value;
                DeleteElem(node.Right, tmp.Value);
            }
        }

        /// <summary>
        /// Deletes element from the tree.
        /// </summary>
        /// <param name="value"></param>
        public void DeleteElem(int value)
        {
            DeleteElem(Root, value);
        }

        protected void PrintInOrder(TreeNode node)
        {
            if (node != null)
            {
                if (node.Left != null)
                    PrintInOrder(node.Left);
                Console.Write("{0} ", node.Value);
                if (node.Right != null)
                    PrintInOrder(node.Right);
            }
        }

        /// <summary>
        /// Prints elements of tree in direct order.
        /// </summary>
        public void PrintInOrder()
        {
            PrintInOrder(Root);
        }

        protected void PrintInRevOrder(TreeNode node)
        {
            if (node != null)
            {
                if (node.Right != null)
                    PrintInRevOrder(node.Right);
                Console.Write("{0} ", node.Value);
                if (node.Left != null)
                    PrintInRevOrder(node.Left);
            }
        }

        /// <summary>
        /// Prints elements of tree in reverce order.
        /// </summary>
        public void PrintInRevOrder()
        {
            PrintInRevOrder(Root);
        }
    }
}
