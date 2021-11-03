namespace PartOne
{
    class Counter
    {
        // Il campo è reso inaccessibile direttamente
        private int value;

        // E' il costruttore che inizializza i campi!
        public Counter() : this(0) // Riusa l’altro costruttore
        {
        }

        // Un costruttore con parametro
        public Counter(int value)
        {
            this.value = value;
        }

        // Unico modo per osservare lo stato 
        // N.B. in C# sarebbe più opportuna una proprità
        public int GetValue()
        {
            return this.value;
        }

        // Unico modo per modificare lo stato
        public void Inc()
        {
            this.value++;
        }
    }
}