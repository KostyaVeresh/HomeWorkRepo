using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace problem_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private double resValue;
        private char operation = ' ';
        private bool numberIsPrinted = true;

        private void takeNumber(int num)
        {
            if (numberIsPrinted)
            {
                labelResult.Text = "";
                numberIsPrinted = false;
            }
            labelResult.Text += num;
        }

        private void SaveValue()
        {
            if (labelResult.Text != "0")
            {
                resValue = double.Parse(labelResult.Text);
                numberIsPrinted = true;
            }
        }

        private void countResult()
        {
            switch (operation)
            {
                case '+':
                    resValue += double.Parse(labelResult.Text);
                    break;
                case '-':
                    resValue -= double.Parse(labelResult.Text);
                    break;
                case '*':
                    resValue *= double.Parse(labelResult.Text);
                    break;
                case '/':
                    resValue /= double.Parse(labelResult.Text);
                    break;
            }
            labelResult.Text = "";
            labelResult.Text += resValue;
            numberIsPrinted = true;
        }

        private void doOperation(char oper)
        {
            if (operation != ' ' && double.Parse(labelResult.Text) != resValue)
                countResult();
            else
                SaveValue();
            labelOper.Text = oper.ToString();
            operation = oper;
        }

        private void button0_Click(object sender, EventArgs e)
        {
            takeNumber(0);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            takeNumber(1);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            takeNumber(2);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            takeNumber(3);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            takeNumber(4);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            takeNumber(5);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            takeNumber(6);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            takeNumber(7);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            takeNumber(8);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            takeNumber(9);
        }

        private void buttonPlus_Click(object sender, EventArgs e)
        {
            doOperation('+');
        }

        private void buttonMinus_Click(object sender, EventArgs e)
        {
            doOperation('-');
        }

        private void buttonMultiply_Click(object sender, EventArgs e)
        {
            doOperation('*');
        }

        private void buttonDivide_Click(object sender, EventArgs e)
        {
            doOperation('/');
        }

        private void buttonResult_Click(object sender, EventArgs e)
        {
            countResult();
            labelOper.Text = "";
            operation = ' ';
            resValue = 0;
            numberIsPrinted = true;
        }
    }
}
