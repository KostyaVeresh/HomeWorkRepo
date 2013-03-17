using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_3.Test
{
    [TestClass]
    public class HashTableTest
    {
        private UserHashTable hashTable;
        private int hash_1;
        private int hash_2;
        private int hash_3;

        [TestInitialize]
        public void Initialize()
        {
            hashTable = new UserHashTable(100);
            hash_1 = hashTable.CalculateHash("abcdef");
            hash_2 = hashTable.CalculateHash("faebdc");
            hash_3 = hashTable.CalculateHash("abcdefg");
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
    }
}