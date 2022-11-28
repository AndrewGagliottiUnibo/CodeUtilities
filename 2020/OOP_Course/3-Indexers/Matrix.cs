using System.Linq;

namespace Indexer
{
    class Matrix<TValue>
    {
        private TValue[][] _values;

        public Matrix(int nRows, int nCols)
        {
            this.Cols = nCols;
            this.Rows = nRows;
            this._values = new TValue[nRows][];
            for (int i = 0; i < nRows; i++)
            {
                this._values[i] = new TValue[nCols];
            }
        }

        public int Cols { get; }
        public int Rows { get; }

        public TValue this[int i, int j]
        {
            get { return this._values[i][j]; }
            set { this._values[i][j] = value; }
        }

        public override string ToString()
        {
            return string.Join(
                "\n", 
                this._values.Select(row => "[" + string.Join(", ", row) + "]")
            );
        }
    }
}
