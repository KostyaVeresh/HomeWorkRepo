using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace problem
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_MouseEnter(object sender, EventArgs e)
        {
            //Moves the button by entering the mouse
            if (MousePosition.X - Left > 100)
                button1.Left -= 75;
            else
                button1.Left += 75;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Close the form by the mouse click.
            Close();
        }
    }
}
