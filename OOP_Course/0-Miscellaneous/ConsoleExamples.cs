using System;

namespace it.unibo.oop.example01.slide14
{
    public class ConsoleExamples
    {
        public static void Main()
        {
            Console.WriteLine("Come ti chiami?");
            string name = Console.ReadLine();

            Console.WriteLine("Quanti anni hai?");
            int age = int.Parse(Console.ReadLine());
            Console.WriteLine("{0} ha {1} anni", name, age);

            Console.WriteLine("Valore intero a:");
            int a = int.Parse(Console.ReadLine());
            Console.WriteLine("Valore intero b:");
            int b = int.Parse(Console.ReadLine());

            Console.WriteLine("1) a+b\n2) a*b");
            int c = Console.Read();

            int r;
            switch (c)
            {
                case '1':
                    r = a + b;
                    break;
                case '2':
                    r = a * b;
                    break;
                default:
                    Console.WriteLine("Err");
                    return;
            }

            Console.WriteLine("Risultato: {0}", r);
        }
    }
}