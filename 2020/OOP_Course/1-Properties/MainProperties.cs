using System;

namespace Properties
{
    class MainProperties
    {
        static void Main(string[] args)
        {
            Person mario = new Person("Mario", "Rossi", new DateTime(1994, 1, 4));

            Console.WriteLine(mario);
            Console.ReadKey();

            //giovanni.Age = 25;

            //Console.WriteLine(mario);
            //Console.ReadKey();

            //Person luigi = new Person() {
            //    FullName = "Luigi Bianchi",
            //    BirthDate = new DateTime(1992, 1, 4)
            //};

            //Console.WriteLine(luigi);
            //Console.ReadKey();
        }
    }
}
