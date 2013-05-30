using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_1
{
    public class CountTree
    {
        private string expression;
        private int counter;
        private Node root;

        public Node Root()
        {
            return root.Left;
        }

        private Node NodeType(char sym)
        {
            if (sym == '+')
                return new Add();
            if (sym == '-')
                return new Substract();
            if (sym == '*')
                return new Multiply();
            if (sym == '/')
                return new Divide();
            return new Number();
        }

        private void AddNode(Node pos, bool fact)
        {
            char sym = 'a';
            if (counter < expression.Length)
            {
                sym = expression[counter];
                ++counter;
                if (sym != '(' && sym != ')' && sym != ' ')
                {
                    Node tmp = NodeType(sym);
                    tmp.Value = sym;
                    if (fact)
                        pos.Left = tmp;
                    else
                        pos.Right = tmp;
                    AddNode(pos.Left, true);
                    AddNode(pos, false);
                }
                if (sym == '(')
                    AddNode(pos, true);
            }
        }

        public CountTree(string str)
        {
            root = new Add();
            counter = 0;
            using (StreamReader f = new StreamReader(str))
            {
                expression = f.ReadLine();
            }     
            AddNode(root, true);
        }

        public int Count()
        {
            return root.Left.Action();
        }

        public void Print()
        {
            root.Left.Print();
        }
    }
}
