using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_1
{
    public class TreeIterator: IEnumerator
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
            CreateListOfElements(tree.Root);
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
}
