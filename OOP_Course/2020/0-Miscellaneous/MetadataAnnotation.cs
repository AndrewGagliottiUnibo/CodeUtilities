using System;

namespace PartOne
{
    public class A
    {
        protected virtual void m(int x)
        {
        }
    }

    class B : A
    {
        override // N.B. in C# è una keyword obbligatoria
            protected void m(int x)
        {
        }

//        override
//        protected void m(string x) { } // comp. error

        [Obsolete]
        public void Old()
        {
        } // comp. warning se usato

        public static void Main(string[] args)
        {
            new B().Old();

#pragma warning disable 0612, 0618
            new B().Old();
        }
    }
}