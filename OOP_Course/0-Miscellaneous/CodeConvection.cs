using System;

namespace it.unibo.oop.example01.slide10
{
    class CodeConvection
    {
        private static int mySum;

        public static void Main(string[] args)
        {
            mySum = SumTwoNum(10, 5);
            Console.WriteLine(mySum.ToString());
        }

        private static int SumTwoNum(int firstPar, int secondPar)
        {
            return firstPar + secondPar;
        }
    }
}