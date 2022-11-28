using System;
using System.Collections.Generic;
using System.Linq;

namespace Iterators
{
    static class MyEnumerable
    {
        public static IEnumerable<Tuple<int, TAny>> Indexed<TAny>(this IEnumerable<TAny> sequence)
        {
            int index = 0;
            foreach (var element in sequence)
            {
                yield return Tuple.Create(index++, element);
            }
        }

        public static IEnumerable<TAny> EvenPositions<TAny>(this IEnumerable<TAny> sequence)
        {
            return sequence.Indexed()
                .Where(indexed => indexed.Item1 % 2 == 0)
                .Select(indexed => indexed.Item2);
        }

        public static void ForEach<TAny>(this IEnumerable<TAny> sequence, Action<TAny> consumer)
        {
            foreach (var element in sequence)
            {
                consumer(element);
            }   
        }

        public static IEnumerable<TOut> Map<TIn, TOut>(this IEnumerable<TIn> sequence, Func<TIn, TOut> mapping)
        {
            foreach (var element in sequence)
            {
                yield return mapping(element);
            }
        }

    }
    class Iterators
    {
        static void Main(string[] args)
        {
            Enumerable.Range(0, 26)
                .Map(i => char.ConvertFromUtf32('A' + i))
                .Indexed()
                .ForEach(Console.WriteLine);

            Console.ReadLine();
        }
    }
}
