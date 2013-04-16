using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_3.Test
{
    [TestClass]
    public class HashTableTest
    {
        private HashTable hashTable;
        private int hash_1;
        private int hash_2;
        private int hash_3;

        [TestInitialize]
        public void Initialize()
        {
            hashTable = new HashTable(100);
            hash_1 = hashTable.CalculateHash("abcdef", 100);
            hash_2 = hashTable.CalculateHash("faebdc", 100);
            hash_3 = hashTable.CalculateHash("abcdefg", 100);
        }

        [TestMethod]
        public void CalculateHashTest()
        {
            Assert.IsTrue(hash_1 == hash_2 && hash_1 != hash_3);
            Assert.IsTrue(hash_1 < hashTable.hashSize && hash_3 < hashTable.hashSize);
        }

        [TestMethod]
        public void AddValueTest()
        {
            hashTable.AddValue("abcdef");
            hashTable.AddValue("faebdc");
            var elem = hashTable.Table[hash_1].Head.Next;
            Assert.AreEqual("abcdef", elem.Str);
            Assert.AreEqual("faebdc", elem.Next.Str);
        }

        [TestMethod]
        public void AddValueCountTest()
        {
            for (int i = 0; i < 3; ++i)
                hashTable.AddValue("abcdef");
            for (int i = 0; i < 7; ++i)
                hashTable.AddValue("faebdc");
            var elem = hashTable.Table[hash_1].Head.Next;
            Assert.AreEqual(3, elem.Count);
            Assert.AreEqual(7, elem.Next.Count);
        }

        [TestMethod]
        public void UserHashTableTest()
        {
            HashTable userHashTable = new HashTable(100, Program.CalculateHash2);
            userHashTable.AddValue("abcdef");
            userHashTable.AddValue("aaebdc");
            var hash = userHashTable.CountHash("abcdef", 100);
            var elem = userHashTable.Table[hash].Head.Next;
            Assert.AreEqual("abcdef", elem.Str);
            Assert.AreEqual("aaebdc", elem.Next.Str);
            hash = userHashTable.CountHash("zzzdef", 100);
            userHashTable.AddValue("zzzdef");
            userHashTable.AddValue("zzzbdc");
            elem = userHashTable.Table[hash].Head.Next;
            Assert.AreEqual("zzzdef", elem.Str);
            Assert.AreEqual("zzzbdc", elem.Next.Str);
        }
    }
}