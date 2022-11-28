using System;
using PartOne.Case2;

namespace PartOne
{
    public class Polymorphism2
    {
        public static void Main(string[] arg)
        {
            Persona A = new Persona();
            Studente B = new Studente();
            Persona C = B; // Corretto: non richiede cast
            Studente D = (Studente) C; // Corretto ma richiede cast
            Studente E = (Studente) A; // Genera errore a run-time
            Studente F = C as Studente; // Corretto: F=C
            Studente G = A as Studente; // Corretto: G=null

            bool b1 = (A is Persona) && (B is Studente); // true
            bool b2 = F is Studente; // true
            bool b3 = A is Studente; // false
            bool b4 = G is Studente; // false
            bool b5 = B is Object; // true
        }
    }
}