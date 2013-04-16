using System;
using System.IO;

namespace problem_3
{
    

    public class Program
    {
        /// <summary>
        /// User's hash function
        /// </summary>
        /// <param name="str"></param>
        /// <param name="hashSize"></param>
        static public int CalculateHash2(string str, int hashSize)
        {
            return str[0] % hashSize;
        }

        static void Main(string[] args)
        {
            const int hashsize = 100;
            HashTable hashTable = new HashTable(hashsize);

            StreamReader sr = new StreamReader("newfile.txt");
            while (!sr.EndOfStream)
            {
                string[] temp = sr.ReadLine().Split(' ');
                for (int i = 0; i < temp.Length; ++i)
                    if (temp[i] != "")
                        hashTable.AddValue(temp[i]);
            }
            sr.Close();
            hashTable.PrintHashTable();
            Console.ReadLine();
        }
    }
}