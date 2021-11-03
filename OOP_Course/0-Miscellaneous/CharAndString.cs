using System;
using System.Text;

namespace PartOne
{
    public class CharAndString
    {
        public static void Main(string[] args)
        {
            char newLine = '\n';
            int n = (int) newLine; // 13
            char test = (char) 13; // ‘\n’

            // Concatenazione
            string u = "Bologna";
            u = "Università di " + u; //"Università di Bologna"

            // Confronto
            string c = "Cesena";
            bool e1 = c == "Cesena"; // confronta i caratteri
            bool e2 = c.Equals("Cesena"); // true
            bool e3 = c.Equals("Cesena", StringComparison.InvariantCultureIgnoreCase); //true
            bool e4 = c.CompareTo("Cesena") == 0; // true

            // Formattazione date
            DateTime d = new DateTime(1974, 12, 29);
            string s = string.Format("Data: {0:dd/MM/yyyy}", d);

            // Modifica e concatenazione efficiente
            StringBuilder buffer = new StringBuilder("due ");
            buffer.Append("tre ");
            buffer.Insert(0, "uno ");
            buffer.Replace("due", "DUE");
            Console.WriteLine(buffer); // "uno DUE tre"

            foreach (char ch in s)
            {
                Console.WriteLine(ch);
            }
        }
    }
}