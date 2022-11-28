using System;
using System.Collections.Generic;

namespace PartOne
{
    public class Pair<X, Y>
    {
        private X first;
        private Y second;

        public Pair(X first, Y second)
        {
            this.first = first;
            this.second = second;
        }

        public X GetFirst()
        {
            return this.first;
        }

        public Y GetSecond()
        {
            return this.second;
        }

        public override string ToString()
        {
            return "<" + first + "," + second + ">";
        }

        public static void Main(string[] args)
        {
            List<Pair<string, int>> v = new List<Pair<string, int>>();
            v.Add(new Pair<string, int>("Prova", 1));
            v.Add(new Pair<string, int>("di", 2));
            v.Add(new Pair<string, int>("Vettore", 3));

            foreach (Pair<string, int> pair in v)
            {
                Console.WriteLine(pair);
            }
        }
    }
}