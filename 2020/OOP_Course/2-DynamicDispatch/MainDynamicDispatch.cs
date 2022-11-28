using System;

namespace LezioneCSharp
{

    class A
    {
        public virtual string GetValue()
        {
            return "a";
        }
    }

    class B : A
    {
        public override string GetValue()
        {
            return "b";
        }
    }
    static class MainDynamicDispatch
    {
        static void Print(A x)
        {
            Console.WriteLine("A: " + x.GetValue());
        }

        static void Print(B x)
        {
            Console.WriteLine("B: " + x.GetValue());
        }

        static void Main(string[] args)
        {
            A a = new A();
            B b = new B();
            A b1 = b;
            //B b1 = b;
            //object b1 = b;
            //dynamic b1 = b;

            Print(a);
            Print(b);
            Print(b1);

            Console.ReadKey();
        }
    }
}