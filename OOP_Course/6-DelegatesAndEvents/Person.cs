namespace Delegates {

    delegate void ValueEditAction<in TType>(TType value);

    class Person
    {
        private string _name;
        private string _surname;
        private int _age;

        public Person(string name, string surname, int age)
        {
            this._name = name;
            this._surname = surname;
            this._age = age;
        }

        public string Name
        {
            get { return this._name; }
            set
            {
                this._name = value;
                if (this.NameChanged != null)
                {
                    this.NameChanged(value);
                }
            }
        }

        public string Surname
        {
            get { return this._surname; }
            set
            {
                this._surname = value;
                if (this.SurnameChanged != null)
                {
                    this.SurnameChanged(value);
                }
            }
        }

        public int Age
        {
            get { return this._age; }
            set
            {
                this._age = value;
                if (this.AgeChanged != null)
                {
                    this.AgeChanged(value);
                }
            }
        }

        public event ValueEditAction<string> NameChanged;
        public event ValueEditAction<string> SurnameChanged;
        public event ValueEditAction<int> AgeChanged;
    }

}