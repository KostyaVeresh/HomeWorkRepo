using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_1
{
    public class ListIterator<T> : IEnumerator<T>
    {
        private ListElement<T> pos;
        private int numberOfPos;
        private List<T> list;

        public ListIterator(List<T> list)
        {
            this.pos = list.First;
            this.list = list;
        }

        public bool MoveNext()
        {
            ++this.numberOfPos;
            this.pos = pos.Next;
            return numberOfPos < this.list.SizeOfList() + 1;
        }

        public T Current
        {
            get
            {
                return this.pos.Value;
            }
        }

        object IEnumerator.Current
        {
            get
            {
                return Current;
            }
        }

        public void Reset()
        {
            this.pos = this.list.First;
            numberOfPos = 0;
        }

        public void Dispose() { }
    }
}
