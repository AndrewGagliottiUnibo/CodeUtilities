using System;

namespace PartOne
{
    partial class Program
    {
        static void M1(int n)
        {
            n++;
            Console.WriteLine("N inside m1 = " + n);
        }

        static void M2(ref int n)
        {
            n++;
            Console.WriteLine("N inside m2 = " + n);
        }

        static void M3(out int a)
        {
            a = 10;
            Console.WriteLine("P inside M3 = " + a);
        }

        static void M4(params int[] v)
        {
        }

        static int Sum(int x, int y = 0)
        {
            return x + y;
        }

        public static void Main(string[] args)
        {
            int n = 0;
            Console.WriteLine("N inside Main() = " + n);
            Console.WriteLine("Calling M1()");
            M1(n);
            Console.WriteLine("N inside Main() = " + n);
            Console.WriteLine("Calling M2()");
            M2(ref n);
            Console.WriteLine("N inside Main() = " + n);

            int p;
            Console.WriteLine("Calling M3()");
            M3(out p);
            Console.WriteLine("P inside Main() = " + p);

            M4(1, 2, 3);

            int s1 = Sum(1, 2);
            int s2 = Sum(5);
        }
    }
}