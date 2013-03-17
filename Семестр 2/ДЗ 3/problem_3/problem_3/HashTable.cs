using System;

namespace problem_3
{
    public class HashTable
    {
        public int hashSize { get; private set; }
        public List[] Table { get; private set; }

        public HashTable(int hashsize)
        {
            Table = new List[hashsize];
            for (int i = 0; i < hashsize; ++i)
                Table[i] = new List();
            hashSize = hashsize;
        }

        public void PrintHashTable()
        {
            for (int i = 1; i < hashSize; ++i)
                if (!Table[i].IsEmpty())
                    Table[i].PrintList();
        }

        public virtual int CalculateHash(string str)
        {
            int result = 0;
            for (int i = 0; i < str.Length; ++i)
            {
                result += str[i];
            }
            return result % hashSize;
        }

        public void AddValue(string value)
        {
            int key = CalculateHash(value);
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