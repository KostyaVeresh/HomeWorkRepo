using System;
using System.IO;

namespace problem_3
{
    public class UserHashTable : HashTable
    {
        public override int CalculateHash(string str) // here can be user's hash function
        {
            int result = 0;
            for (int i = 0; i < str.Length; ++i)
            {
                result += str[i];
            }
            return result % hashSize;
        }

        public UserHashTable(int hashsize) : base(hashsize)
        {
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            const int hashsize = 100;
            HashTable hashTable = new UserHashTable(hashsize);
            StreamReader sr = new StreamReader("newfile.txt");
            while (!sr.EndOfStream)
            {
                string[] temp = sr.ReadLine().Split(' ');
                for (int i = 0; i < temp.Length; ++i)
                    hashTable.AddValue(temp[i]);
            }
            sr.Close();
            hashTable.PrintHashTable();
            Console.ReadLine();
        }
    }
}