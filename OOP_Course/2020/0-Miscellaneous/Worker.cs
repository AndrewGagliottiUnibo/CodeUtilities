using System;
using System.Threading;

namespace PartOne
{
    class Worker
    {
        public void Action()
        {
            Console.Write("print on different thread");
        }

        public void Main()
        {
            // ThreadStart is a delegate, equivalent to Runnable
            ThreadStart action = this.Action;

            // we store the run method as a delegate;
            // note that parenthesis are missing,
            // like in Java with method references

            // or anonimously as delegate ...

            action = delegate { Console.Write("print on different thread"); };

            // or anonimously as lambda ...

            action = () => Console.Write("print on different thread");

            // in both cases ...

            new Thread(action).Start();
        }
    }

    namespace Esempio1
    {
        class Worker
        {
            private const int Times = 10;
            private readonly string name;

            public Worker(string name)
            {
                this.name = name;
            }

            public void Run()
            {
                for (int i = 0; i < Times; i++)
                {
                    Console.WriteLine($"{i} Hello world, by {name}");
                    Console.WriteLine($"{i} I'm {name} again");
                }
            }

            public static void Main(string[] args)
            {
                for (int i = 0; i < 5; i++)
                {
                    // ThreadStart is a delegate, equivalent to Runnable
                    ThreadStart runnable = new Worker($"Foo{i}").Run;

                    // we store the run method as a delegate;
                    // note that parenthesis are missing,
                    // like in Java with method references

                    new Thread(runnable).Start();
                }
            }


        }
    }

    namespace Esempio2
    {
        class Worker
        {
            private const int Times = 10;
            private readonly string name;
            private readonly object lockObj;

            public Worker(string name, object lockObj)
            {
                this.name = name;
                this.lockObj = lockObj;
            }

            public void Run()
            {
                for (int i = 0; i < Times; i++)
                {
                    Console.WriteLine($"{i}: Hello world from {name}!");
                    lock (lockObj)
                    {
                        Console.Write($"{i}: I'm {name} and ");
                        Console.Write($"I'm {name} again");
                    }
                }
            }

            public static void Main(string[] args)
            {
                object lockObj = new object();
                for (int i = 0; i < 5; i++)
                {
                    new Thread(new Worker($"Foo{i}", lockObj).Run).Start();
                }
            }
        }
    }
}
