using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_3.Test
{
    [TestClass]
    public class HashTableTest
    {
        private HashTable hashTable;

        [TestInitialize]
        public void Initialize()
        {
            hashTable = new HashTable(100);
        }

        [TestMethod]
        public void AddValueTest()
        {
            bool fact = false;
            for (int i = 0; i < 3; ++i)
                hashTable.AddValue("abcdef");
            for (int i = 0; i < 7; ++i)
                hashTable.AddValue("faebdc");
            for (int i = 0; i < 100; ++i)
                if (!hashTable.HashList(i).IsEmpty())
                    if (hashTable.HashList(i).Head.Next.Str == "abcdef" && hashTable.HashList(i).Head.Next.Count == 3)
                        if (hashTable.HashList(i).Head.Next.Next.Str == "faebdc" && hashTable.HashList(i).Head.Next.Next.Count == 7)
                            fact = true;
            Assert.IsTrue(fact);
        }

        [TestMethod]
        public void UserHashTableTest()
        {
            HashTable userHashTable = new HashTable(100, Program.CalculateHash2);
            userHashTable.AddValue("abcdef");
            userHashTable.AddValue("aaebdc");
            var hash = Program.CalculateHash2("abcdef", 100);
            var elem = userHashTable.HashList(hash).Head.Next;
            Assert.AreEqual("abcdef", elem.Str);
            Assert.AreEqual("aaebdc", elem.Next.Str);
            hash = Program.CalculateHash2("zzzdef", 100);
            userHashTable.AddValue("zzzdef");
            userHashTable.AddValue("zzzbdc");
            elem = userHashTable.HashList(hash).Head.Next;
            Assert.AreEqual("zzzdef", elem.Str);
            Assert.AreEqual("zzzbdc", elem.Next.Str);
        }
    }
}