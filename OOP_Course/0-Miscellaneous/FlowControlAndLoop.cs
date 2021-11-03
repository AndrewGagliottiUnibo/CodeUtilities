using System;
using System.Collections;

namespace PartOne
{
    public class FlowControlAndLoop
    {
        public static void Main(string[] args)
        {
            int j = 0;
            while (j < 10)
            {
                j++;
            }

            for (int i = 2; i <= 10; i += 2)
            {
                Console.WriteLine(i);
            }

            do
            {
                j++;
            } while (j < 20);

            int sum = 0;
            int[] array = new int[] {1, 2, 3};
            foreach (int k in array)
            {
                sum += k;
            }

            ArrayList list = new ArrayList();
            list.Add(42);
            list.Add("unibo");
            list.Add(3.14);

            foreach (object o in list)
            {
                Console.WriteLine(o);
            }
        }
    }
}