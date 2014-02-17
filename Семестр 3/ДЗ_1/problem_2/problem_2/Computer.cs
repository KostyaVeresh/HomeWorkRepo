﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_2
{
    public class Computer
    {
        public bool IsVirused { get; private set; }
        private char os;

        public Computer(char os, bool virused)
        {
            this.IsVirused = virused;
            this.os = os;
        }

        public void Infect()
        {
            Random rnd = new Random();
            Infect(rnd.Next(0,100));
        }

        public void Infect(int value)
        {
            switch (this.os)
            {
                case 'w':
                    if (value < 50)
                        this.IsVirused = true;
                    break;
                case 'm':
                    if (value < 40)
                        this.IsVirused = true;
                    break;
                case 'l':
                    if (value < 30)
                        this.IsVirused = true;
                    break;
            }
        }
    }
}
