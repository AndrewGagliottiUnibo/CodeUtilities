using System;

namespace PartOne
{
    public class ArrayExample
    {
        public static void Main(string[] args)
        {
            int[] v = new int[] {5, 4, 3, 2, 1};
            for (int i = 0; i < v.Length; i++)
            {
                Console.WriteLine(v[i]);
            }

            string[] nomi = new string[5];
            nomi[0] = "Anders Hejlsberg";

            float[,] mat = new float[,]
            {
                {1, 2, 3},
                {5, 8, 13}
            };
            mat[1, 0] = 4.2f;

            int r = mat.Rank; // 2 (numero di dimensioni)
            int tot = mat.Length; // 6 (totale elementi)
            int rows = mat.GetLength(0); // 2 (numero righe)
            int cols = mat.GetLength(1); // 3 (numero colonne)

            int[][] jagged = new int[3][]
            {
                new int[5],
                new int[2],
                new int[3]
            };

            jagged[0][4] = 5;

            int[] v2 = v; // N.B. non crea una copia
            int[] v3 = (int[]) v.Clone(); // Crea una copia

            Array.Sort(v); // 1, 2, 3, 4, 5
            Console.WriteLine("[{0}]", string.Join(",", v));
            int j = Array.BinarySearch(v, 2); // 1
            Array.Reverse(v); // 1, 2, 3, 4, 5        
        }
    }
}