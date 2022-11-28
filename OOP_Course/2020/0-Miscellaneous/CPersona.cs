using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace PartOne
{
    [Serializable]
    public class CPersona
    {
        private String nome;
        private int annoNascita;

        public CPersona(string nome, int annoNascita)
        {
            this.nome = nome;
            this.annoNascita = annoNascita;
        }

        [NonSerialized] private String cachedToString;
        // ...

        override public string ToString()
        {
            if (this.cachedToString == null)
            {
                cachedToString = nome + ":" + annoNascita;
            }

            return this.cachedToString;
        }

        private static readonly string STR = "p.bin";

        public static void Main()
        {
            var bf = new BinaryFormatter();
            var fOut = new FileStream(STR, FileMode.Create);
            CPersona p = new CPersona("Rossi", 1960);
            Console.WriteLine("1) " + p); // cache vuota
            Console.WriteLine("2) " + p); // cache non vuota
            bf.Serialize(fOut, new CPersona("Rossi", 1960));
            fOut.Close();
            Console.WriteLine("Ri-carico l'oggetto... ");
            var fIn = new FileStream(STR, FileMode.Open);
            CPersona q = (CPersona) bf.Deserialize(fIn);
            Console.WriteLine("1) " + q); // cache vuota
            Console.WriteLine("2) " + q); // cache non vuota
            fIn.Close();
        }
    }
}
