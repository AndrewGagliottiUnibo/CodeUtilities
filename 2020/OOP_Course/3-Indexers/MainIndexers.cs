using System;

namespace Indexer
{
    class MainIndexers
    {
        static void Main(string[] args)
        {
            Map2d<string, DateTime, int> map = new Map2d<string, DateTime, int>();

            map["Giovanni", DateTime.Today] = 8;
            map["Mirko", DateTime.Today.AddDays(2)] = 0;
            map["Giovanni", DateTime.Today.AddDays(2)] = 0;

            Console.WriteLine(map);
            Console.ReadKey();
        }
    }
}
