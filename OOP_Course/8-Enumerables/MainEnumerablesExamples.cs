using System;
using System.Linq;

namespace EnumerablesExamples
{
    class EnumerablesExamples
    {
        static readonly string[] books = new string[] {
            "VB .NET Tutorials for dummies",
            "Learn C ++ the hard way",
            "MVC tutorials for .Net developers" ,
            "Java Official Reference",
            "Java Stream Tutorial",
            "C# Tutorials -- The handbook",
            "Python 3 - The the ultimate guide",
            "Why Python 2 won't die",
            "IronPython tutorial",
            "Effective Java"
        };

        static void Main(string[] args)
        {

            var bookInfo = books
                .Where(title => title.Contains("utorial"))
                .OrderBy(title => title.Length)
                .Select(title => new {
                    Title = title,
                    Length = title.Length,
                    NumOfWords = title.Split(' ').Length
                });

            Console.WriteLine("Press enter...");
            Console.ReadKey();

            foreach (var book in bookInfo)
            {
                Console.WriteLine(book);
            }

            Console.WriteLine("Press enter again...");
            Console.ReadKey();

            foreach (var book in bookInfo)
            {
                Console.WriteLine(book);
            }

            Console.ReadKey();
        }

        static void Main2(string[] args)
        {
            int sideEffect = 0;

            var bookInfo = books
                .Where(title => title.Contains("utorial"))
                .OrderBy(title => title.Length)
                .Select(title => (sideEffect++) + "|" + title)
                .Select(title => new {
                    Title = title,
                    Length = title.Length,
                    NumOfWords = title.Split(' ').Length
                });

            Console.WriteLine("Press enter...");
            Console.ReadKey();

            foreach (var book in bookInfo)
            {
                Console.WriteLine(book);
            }

            Console.WriteLine("Press enter again...");
            Console.ReadKey();

            foreach (var book in bookInfo)
            {
                Console.WriteLine(book);
            }

            Console.ReadKey();
        }

        static void Main3(string[] args)
        {

            var bookInfo = from title in books
                where title.Contains("utorial")
                orderby title.Length
                select new {
                    Title = title,
                    Length = title.Length,
                    NumOfWords = title.Split(' ').Length
                };

            Console.WriteLine("Press enter...");
            Console.ReadKey();

            foreach (var book in bookInfo)
            {
                Console.WriteLine(book);
            }

            Console.WriteLine("Press enter again...");
            Console.ReadKey();

            foreach (var book in bookInfo)
            {
                Console.WriteLine(book);
            }

            Console.ReadKey();
        }
    }


}
