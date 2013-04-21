using System;

namespace problem_3
{
    /// <summary>
    /// Hash table of strings.
    /// </summary>
    public class HashTable
    {
        public int HashSize { get; private set; }
        public List[] Table { get; private set; }
        public delegate int HashFunction(string str, int hashSize);

        public HashFunction CountHash { get; private set; }

        /// <summary>
        /// Creates new hashtable of empty elements, takes a function for the hash table.
        /// </summary>
        /// <param name="hashsize"></param>
        public HashTable(int hashsize, HashFunction CountHash)
        {
            Table = new List[hashsize];
            for (int i = 0; i < hashsize; ++i)
                Table[i] = new List();
            HashSize = hashsize;
            this.CountHash = CountHash;
        }

        /// <summary>
        /// Creates hashtable of empty elements.
        /// </summary>
        /// <param name="hashsize"></param>
        public HashTable(int hashsize)
        {
            Table = new List[hashsize];
            for (int i = 0; i < hashsize; ++i)
                Table[i] = new List();
            HashSize = hashsize;
            this.CountHash = this.CalculateHash;
        }

        /// <summary>
        /// Prints elements of the hash table in order from 1st to number of hashsize.
        /// </summary>
        public void PrintHashTable()
        {
            for (int i = 1; i < HashSize; ++i)
                if (!Table[i].IsEmpty())
                    Table[i].PrintList();
        }

        /// <summary>
        /// Returns the hash function of string.
        /// </summary>
        /// <param name="str"></param>
        public int CalculateHash(string str, int hashSize)
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
            int key = CountHash(value, HashSize);
            if (Table[key].Head.Next == null)
            {
                Table[key].AddElem(Table[key].Head, value);
                Table[key].Head.Next.Count = 1;
            }
            else
            {
                var tmp = Table[key].Head;
                while (tmp.Next.Str != value)
                {
                    tmp = tmp.Next;
                    if (tmp.Next == null)
                        break;
                }
                if (tmp.Next == null)
                {
                    Table[key].AddElem(tmp, value);
                    tmp.Next.Count = 1;
                }
                else
                    tmp.Next.Count += 1;
            }
        } 
    }
}