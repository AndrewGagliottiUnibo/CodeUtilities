using System.Collections.Generic;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Test
{
    [TestClass]
    public class SampleTest
    {
        [TestMethod]
        public void Fail()
        {
            Assert.Fail("We want to fail here");
        }

        [TestMethod]
        public void DoubleEquals()
        {
            Assert.AreEqual(0.3, 0.1 + 0.2, 0.00001);
        }

        [TestMethod]
        public void ConditionCheck()
        {
            var list = new List<int> { 1, 2 };
            Assert.IsTrue(list.Any());
            Assert.IsFalse(list.Any(num => num > 2));
        }
    }
}
