﻿using System;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace problem_3.Test
{
    [TestClass]
    public class ProgramTest
    {
        [TestMethod]
        public void FoldTest()
        {
            Assert.AreEqual(6, Program.Fold(new List<int>() { 1, 2, 3 }, 1, (acc, elem) => acc * elem));
        }
    }
}
