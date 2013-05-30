using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_2.Test
{
    [TestClass]
    public class UniqueListTest
    {
        private UniqueList list;

        [TestInitialize]
        public void Initialize()
        {
            list = new UniqueList();
            list.AddElem(1);
            list.AddElem(2);
            list.AddElem(3);
        }

        [TestMethod]
        [ExpectedException(typeof(AddExistentElementException))]
        public void AddElemUniqueListTest()
        {
            list.AddElem(1);
        }

        [TestMethod]
        [ExpectedException(typeof(DeleteNonexistentElementException))]
        public void DeleteElemUniqueListTest()
        {
            list.DeleteElem(1);
            list.DeleteElem(7);
        }
    }
}
