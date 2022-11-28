using System;

namespace PartOne.Case1
{
    class Persona
    {
        public void StampaDesc()
        {
            Console.WriteLine("{0} {1}, anni {2}", "Nome", "Cognome", "Età");
        }
    }

    class Studente : Persona
    {
        public new void StampaDesc()
        {
            base.StampaDesc();
            Console.WriteLine("Mat: {0}, Isc: {1}", "Matricola", "Anno Iscrizione");
        }
    }

    class Program
    {
        public static void Main(string[] args)
        {
            Persona A = new Persona();
            Studente B = new Studente();
            Persona C = B;
            A.StampaDesc(); // Persona.StampaDesc()
            B.StampaDesc(); // Studente.StampaDesc()
            C.StampaDesc(); // Persona.StampaDesc()       
        }
    }
}

namespace PartOne.Case2
{
    class Persona
    {
        public virtual void StampaDesc()
        {
            Console.WriteLine("{0} {1}, anni {2}", "Nome", "Cognome", "Età");
        }
    }

    class Studente : Persona
    {
        public override void StampaDesc()
        {
            base.StampaDesc();
            Console.WriteLine("Mat: {0}, Isc: {1}", "Matricola", "Anno Iscrizione");
        }
    }

    class Program
    {
        public static void Main(string[] args)
        {
            Persona A = new Persona();
            Studente B = new Studente();
            Persona C = B;
            A.StampaDesc(); // Persona.StampaDesc()
            B.StampaDesc(); // Studente.StampaDesc()
            C.StampaDesc(); // Studente.StampaDesc()       
        }
    }
}