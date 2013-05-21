using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_4
{
    class Program
    {
        static void Main(string[] args)
        {
            var eventLoop = new EventLoop();
            var control = new Control();
            eventLoop.leftHandler += control.OnLeft;
            eventLoop.rightHandler += control.OnRight;
            eventLoop.upHandler += control.Up;
            eventLoop.downHandler += control.Down;
            eventLoop.Run();
        }
    }
}
