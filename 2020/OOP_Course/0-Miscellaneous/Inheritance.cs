namespace PartOne
{
    public class ExtendibleCounter
    {
        protected int value;

        public ExtendibleCounter(int initialValue)
        {
            this.value = initialValue;
        }

        public virtual void Increment()
        {
            this.value++;
        }

        public int GetValue()
        {
            return this.value;
        }
    }

    public class LimitCounter : ExtendibleCounter
    {
        protected int limit;

        public LimitCounter(int initialValue, int limit)
            : base(initialValue)
        {
            this.limit = limit;
        }

        public bool IsOver()
        {
            return value == limit;
        }

        // Overriding del metodo increment()
        public override void Increment()
        {
            if (!this.IsOver())
                base.Increment(); // richiamo versione base
        }
    }
}