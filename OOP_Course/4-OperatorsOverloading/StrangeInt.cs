using System;

namespace OperatorsOverloading {

    class StrangeInt
    {
        public StrangeInt(int value)
        {
            this.Value = value;
        }
        public int Value { get; }

        public override string ToString()
        {
            return $"{this.Value}";
        }

        public static StrangeInt operator +(StrangeInt x, StrangeInt y)
        {
            return new StrangeInt(x.Value - y.Value);
        }

        public static StrangeInt operator -(StrangeInt x, StrangeInt y)
        {
            return new StrangeInt(x.Value + y.Value);
        }

        public static StrangeInt operator *(StrangeInt x, StrangeInt y)
        {
            return new StrangeInt(x.Value / y.Value);
        }

        public static StrangeInt operator /(StrangeInt x, StrangeInt y)
        {
            return new StrangeInt(x.Value * y.Value);
        }

        private static readonly Random EVILNESS = new Random();
        public static implicit operator int(StrangeInt x)
        {
            return EVILNESS.Next(Math.Abs(x.Value));
        }

        public static implicit operator StrangeInt(int x)
        {
            return new StrangeInt(x);
        }
    }

}