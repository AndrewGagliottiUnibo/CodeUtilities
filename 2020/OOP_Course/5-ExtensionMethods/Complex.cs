namespace ExtensionMethods
{
    sealed class Complex
    {
        public double Re { get; }
        public double Im { get; }

        public Complex(double re, double im)
        {
            this.Re = re;
            this.Im = im;
        }

        public static Complex operator +(Complex x, Complex y)
        {
            return new Complex(x.Re + y.Re, y.Im + y.Im);
        }

        public static Complex operator -(Complex x, Complex y)
        {
            return new Complex(x.Re - y.Re, y.Im - y.Im);
        }

        public static Complex operator *(Complex x, Complex y)
        {
            return new Complex(x.Re * y.Re - x.Im * y.Im, x.Im * y.Re + x.Re * y.Im);
        }

        public static Complex operator /(Complex x, Complex y)
        {
            double mod2 = y.Re * y.Re + y.Im * y.Im;
            return new Complex((x.Re * y.Re + x.Im * y.Im) / mod2, (x.Im * y.Re - x.Re * y.Im) / mod2);
        }

        public override string ToString()
        {
            if (this.Im >= 0)
            {
                return $"{this.Re} + i{this.Im}";
            }
            else
            {
                return $"{this.Re} - i{-this.Im}";
            }
        }
    }
}
