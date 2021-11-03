using System;
using System.Collections;
using System.Collections.Generic;

namespace PartOne.Slide41
{
    public class Example1
    {
        public static void Main(string[] args)
        {
            var nums = new List<int> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

            for (var i = nums.Count - 1; i >= 0; i--)
            {
                if (nums[i] % 2 == 1)
                {
                    nums.RemoveAt(i);
                }
            }

            var map = new Dictionary<int, string>();
            foreach (int n in nums)
            {
                // Associa n^3 (come testo) ad ogni numero n
                map.Add(n, (n * n * n).ToString());
            }

            var rnd = new Random();
            for (int i = 0; i < 20; i++)
            {
                var n = rnd.Next(10);
                string str;
                if (map.TryGetValue(n, out str))
                {
                    Console.WriteLine("{0} ==> {1}", n, str);
                }
                else
                {
                    Console.WriteLine("{0} non in cache.", n);
                }
            }
        }
    }

    public class Range : IEnumerable<int>
    {
        readonly private int start;
        readonly private int stop;


        public Range(int start, int stop)
        {
            this.start = start;
            this.stop = stop;
        }


        public IEnumerator<int> GetEnumerator()
        {
            for (int cur = start; cur <= stop; cur++)

            {
                yield return cur;
            }
        }


        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        public static void Main(string[] args)
        {
            foreach (int i in new Range(5, 12))
            {
                Console.WriteLine(i); // 5 6 7 8 9 10 11 12 
            }
        }
    }
}