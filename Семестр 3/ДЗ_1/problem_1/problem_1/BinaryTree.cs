using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_1
{
    public class BinaryTree : IEnumerable
    {
        private Node root;

        /// <summary>
        /// Creates empty tree
        /// </summary>
        public BinaryTree()
        {
            this.root = null;
        }

        private void AddElem(ref Node node, int value)
        {
            if (node == null)
            {
                node = new Node(value);
                return;
            }
	        if (value < node.value)
                AddElem(ref node.left, value);
            else
                AddElem(ref node.right, value);
        }

        /// <summary>
        /// Adds new int value to the tree 
        /// </summary>
        /// <param name="value"></param>
        public void AddElem(int value)
        {
            AddElem(ref root, value);
        }

        /// <summary>
        /// Returns if current node is leaf 
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        private bool IsLeaf(Node node)
        {
	        return node.right == null && node.left == null;
        }

        private bool HasOneChild(Node node)
        {
	        return node.right == null && node.left != null || node.right != null && node.left == null;
        }

        private Node MostLeftChild(Node node)
        {
	        if (node.left != null)
		        return MostLeftChild(node.left);
	        else
		        return node;
        }

        private void DeleteElem(ref Node node, int value)
        {
            if (node.value > value)
                DeleteElem(ref node.left, value);
            else if (node.value < value)
                DeleteElem(ref node.right, value);
            else if (IsLeaf(node))
            {
                node = null;
            }
            else if (HasOneChild(node))
            {
                if (node.left != null)
                {
                    node = node.left;
                }
                else if (node.right != null)
                {
                    node = node.right;
                }
            }
            else
            {
                Node tmp = MostLeftChild(node.right);
                node.value = tmp.value;
		        DeleteElem(ref node.right, tmp.value);
            }
        }

        /// <summary>
        /// Deletes int value from the tree
        /// </summary>
        /// <param name="value"></param>
        public void DeleteElem(int value)
        {
            DeleteElem(ref root, value);
        }

        private void PrintTree(ref Node node)
        {
	        if (node != null)
	        {
		        if (node.left != null)
			        PrintTree(ref node.left);
                Console.Write("{0} ", node.value);
		        if (node.right != null)
			        PrintTree(ref node.right);
	        }
        }

        /// <summary>
        /// Prints elements of tree
        /// </summary>
        public void PrintTree()
        {
            PrintTree(ref root);
        }

        public IEnumerator GetEnumerator()
        {
            return new TreeIterator(this);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        class TreeIterator : IEnumerator
        {
            private List<int> listOfElements = new List<int>();
            private int passed = -1;

            private void CreateListOfElements(Node node)
            {
                if (node == null)
                    return;
                CreateListOfElements(node.left);
                listOfElements.Add(node.value);
                CreateListOfElements(node.right);
            }

            public TreeIterator(BinaryTree tree)
            {
                CreateListOfElements(tree.root);
            }

            public bool MoveNext()
            {
                this.passed++;
                return passed < this.listOfElements.Count;
            }

            public int Current
            {
                get
                {
                    return this.listOfElements[passed];
                }
            }

            object IEnumerator.Current
            {
                get
                {
                    return Current;
                }
            }

            public void Reset() { }

            public void Dispose() { }
        }

        class Node
        {
            public int value;
            public Node left;
            public Node right;

            public Node(int value)
            {
                this.value = value;
                this.right = null;
                this.left = null;
            }
        }
    }
}
