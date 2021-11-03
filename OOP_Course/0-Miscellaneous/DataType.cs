using System;

namespace PartOne
{
    public class DataType
    {
        // Esempi di enum
        enum Action
        {
            START,
            STOP,
            REWIND,
            FORWARD
        };

        // Costanti
        const double PI = 3.14; // iniz. a compile-time
        readonly int Value = 42; // iniz. a runtime

        public static void Main()
        {
            // Tipi valore - Esempi di tipi valore predefiniti
            bool flag = true;
            byte a = 255; // N.B. senza segno
            sbyte b = -128; // N.B. con segno
            char c = 'è';

            // Altri tipi valore predefiniti: short, ushort, int, uint, long,
            // ulong, float, double, decimal

            // Tipi riferimento predefiniti
            object o = new object();
            string s = "C#";

            // Tipi riferimento definibili dal programmatore:
            // array, class, interface, delegate

            // Esempi di conversioni
            int x = 42;
            string y = x.ToString(); // y = "42"
            x = int.Parse(y); // o x = Convert.ToInt32(y);
            double z = 3.5;
            x = (int) z; // x = 3  (tronca i decimali)

            Action action = Action.STOP;

            if (action != Action.START)
            {
                Console.WriteLine(a);
            }
        }
    }
}