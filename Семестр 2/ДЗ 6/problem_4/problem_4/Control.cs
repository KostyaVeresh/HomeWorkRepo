using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_4
{
    class Control
    {
        /// <summary>
        /// puts the cursor on left if it is possible
        /// </summary>
        public void OnLeft()
        {
            int x = Console.CursorLeft;
            int y = Console.CursorTop;
            try
            {
                Console.SetCursorPosition(x - 1, y);
            }
            catch { }
        }

        /// <summary>
        /// puts the cursor on right if it is possible
        /// </summary>
        public void OnRight()
        {
            int x = Console.CursorLeft;
            int y = Console.CursorTop;
            try
            {
                Console.SetCursorPosition(x + 1, y);
            }
            catch { }
        }

        /// <summary>
        /// puts the cursor up if it is possible
        /// </summary>
        public void Up()
        {
            int x = Console.CursorLeft;
            int y = Console.CursorTop;
            try
            {
                Console.SetCursorPosition(x, y - 1);
            }
            catch { }

        }

        /// <summary>
        /// puts the cursor donwn if it is possible
        /// </summary>
        public void Down()
        {
            int x = Console.CursorLeft;
            int y = Console.CursorTop;
            try
            {
                Console.SetCursorPosition(x, y + 1);
            }
            catch { }
        }
    }
}
