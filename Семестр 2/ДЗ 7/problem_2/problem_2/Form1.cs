using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace problem_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            int hour = DateTime.Now.Hour;
            string hourStr = hour.ToString();
            if (hour < 10)
                hourStr = "0" + hourStr;
            int minute = DateTime.Now.Minute;
            string minuteStr = minute.ToString();
            if (minute < 10)
                minuteStr = "0" + minuteStr;
            int second = DateTime.Now.Second;
            string secondStr = second.ToString();
            if (second < 10)
                secondStr = "0" + secondStr;
            label1.Text = hourStr + ":" + minuteStr + ":" + secondStr;
        }
    }
}
