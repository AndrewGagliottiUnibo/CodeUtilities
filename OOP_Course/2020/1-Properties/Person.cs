using System;

namespace Properties
{
    class Person
    {
        private string _name;
        private string _surname;
        public DateTime BirthDate { get; set; }

        public Person() : this("", "", DateTime.Today)
        {
            
        }

        public Person(string name, string surname, DateTime birthDate)
        {
            this._name = name;
            this._surname = surname;
            this.BirthDate = birthDate;
        }

        public override string ToString()
        {
            return "Person(FullName='" + this.FullName + "', Age='" + this.Age + "', BirthDate='" + this.BirthDate.ToShortDateString() + "')";
        }  

        public int Age
        {
            get {
                DateTime now = DateTime.Now;
                DateTime birthDate = this.BirthDate;

                int age = now.Year - birthDate.Year;

                if (now.Month < birthDate.Month 
                    || (now.Month == birthDate.Month && now.Day < birthDate.Day))
                {
                    age--;
                }

                return age;
            }
            set
            {
                int currAge = this.Age;
                int diff = currAge - value;

                this.BirthDate = this.BirthDate.AddYears(diff);
            }
        }

        public string FullName
        {
            get { return this._name + " " + this._surname; }
            set
            {
                var splitted = value.Split(' ');
                this._name = splitted[0];
                this._surname = splitted[1];
            }
        }
    }
}
