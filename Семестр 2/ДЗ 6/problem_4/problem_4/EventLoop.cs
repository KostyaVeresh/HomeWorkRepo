using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_4
{
    class EventLoop
    {
        public event Action leftHandler;
        public event Action rightHandler;
        public event Action upHandler;
        public event Action downHandler;

        /// <summary>
        /// starts the event loop
        /// </summary>
        public void Run()
        {
            while (true)
            {
                var key = Console.ReadKey(true);
                switch (key.Key)
                {
                    case ConsoleKey.LeftArrow:
                        leftHandler();
                        break;
                    case ConsoleKey.RightArrow:
                        rightHandler();
                        break;
                    case ConsoleKey.UpArrow:
                        upHandler();
                        break;
                    case ConsoleKey.DownArrow:
                        downHandler();
                        break;
                    default:
                        Environment.Exit(0);
                        break;
                }
            }
        }
    }
}
