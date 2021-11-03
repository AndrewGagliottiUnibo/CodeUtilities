using System;

namespace NullablesAndOperators
{
    class A
    {
        public string SomeProperty { get; set; }
    }



    class MainNullablesAndOperators
    {
        static void Main(string[] args)
        {
            int? v1 = null; // equivale a Nullable<int> v1 = null;
            Nullable<int> v2 = 42;   // equivale a Nullable<int> v2 = 42;

            Console.WriteLine("V1: {0}", v1 != null ? v1.ToString() : "Sconosciuto"); // oppure ..., v1.HasValue ? Console.WriteLine("V2: {0}", v2!=null ? v2.ToString() : "Sconosciuto");
            Console.WriteLine(v1.GetValueOrDefault()); // 0 (default di int)
            Console.WriteLine(v2.GetValueOrDefault()); // 42
            Console.WriteLine(v1 ?? 3);  // 3
            Console.WriteLine(v2 ?? 3);  // 42
            Console.WriteLine((v1 + 3) == null);  // True (null + 3 = null)
            Console.WriteLine((v2 + 58) == null);  // False (42 + 58 = 100)

            Console.ReadLine();

            A example = new A();
            string v3 = example?.SomeProperty ?? "default string";
            Console.WriteLine(v3);

            example.SomeProperty = "property value";
            string v4 = example?.SomeProperty ?? "default string";
            Console.WriteLine(v4);

            Console.ReadLine();
        }
    }
}
