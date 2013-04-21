using System;

namespace problem_3
{
    /// <summary>
    /// Hash table of strings.
    /// </summary>
    public class HashTable
    {
        public int HashSize { get; private set; }
        private List[] table;
        public delegate int HashFunction(string str, int hashSize);

        //public HashFunction CountHash { get; private set; }
        private HashFunction countHash;

        /// <summary>
        /// Creates new hashtable of empty elements, takes a function for the hash table.
        /// </summary>
        /// <param name="hashsize"></param>
        public HashTable(int hashsize, HashFunction CountHash)
        {
            table = new List[hashsize];
            for (int i = 0; i < hashsize; ++i)
                table[i] = new List();
            HashSize = hashsize;
            this.countHash = CountHash;
        }

        /// <summary>
        /// Creates hashtable of empty elements.
        /// </summary>
        /// <param name="hashsize"></param>
        public HashTable(int hashsize)
        {
            table = new List[hashsize];
            for (int i = 0; i < hashsize; ++i)
                table[i] = new List();
            HashSize = hashsize;
            this.countHash = this.CalculateHash;
        }

        /// <summary>
        /// Prints elements of the hash table in order from 1st to number of hashsize.
        /// </summary>
        public void PrintHashTable()
        {
            for (int i = 1; i < HashSize; ++i)
                if (!table[i].IsEmpty())
                    table[i].PrintList();
        }

        /// <summary>
        /// Returns the hash function of string.
        /// </summary>
        /// <param name="str"></param>
        private int CalculateHash(string str, int hashSize)
        {
            int result = 0;
            for (int i = 0; i < str.Length; ++i)
            {
                result += str[i];
            }
            return result % hashSize;
        }

        /// <summary>
        /// Adds new element to the hash table.
        /// </summary>
        /// <param name="value"></param>
        public void AddValue(string value)
        {
            int key = countHash(value, HashSize);
            if (table[key].Head.Next == null)
            {
                table[key].AddElem(table[key].Head, value);
                table[key].Head.Next.Count = 1;
            }
            else
            {
                var tmp = table[key].Head;
                while (tmp.Next.Str != value)
                {
                    tmp = tmp.Next;
                    if (tmp.Next == null)
                        break;
                }
                if (tmp.Next == null)
                {
                    table[key].AddElem(tmp, value);
                    tmp.Next.Count = 1;
                }
                else
                    tmp.Next.Count += 1;
            }
        }

        /// <summary>
        /// Returns list of hash table.
        /// </summary>
        /// <param name="i"></param>
        public List HashList(int i)
        {
            return table[i];
        }
    }
}