namespace PartOne
{
    using System.IO;

    public class UseDataStream
    {
        private static readonly string P = @"C:\temp\prova.bin";

        public static void Main()
        {
            var f = new FileStream(P, FileMode.Create);
            var ds = new BinaryWriter(f);
            ds.Write(true);
            ds.Write(10000);
            ds.Write(5.2);
            ds.Close();

            var f2 = new FileStream(P, FileMode.Open);
            var ds2 = new BinaryReader(f2);
            System.Console.WriteLine(ds2.ReadBoolean());
            System.Console.WriteLine(ds2.ReadInt32());
            System.Console.WriteLine(ds2.ReadDouble());
            ds2.Close();
        }
    }
}