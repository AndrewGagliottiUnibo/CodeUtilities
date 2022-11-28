namespace PartOne
{
    using System;
    using System.Reflection;

    class DynamicExecution
    {
        readonly static string Q_CLASS = "Nome classe: ";
        readonly static string Q_METH = "Nome metodo: ";
        readonly static string L_OK = "OK: result = ";
        readonly static string E_RET = "Errore tipo di ritorno";

        public static void Main()
        {
            Console.WriteLine(Q_CLASS);
            string className = Console.ReadLine();
            Console.WriteLine(Q_METH);
            string methName = Console.ReadLine();
            Type cl = Type.GetType(className);
            ConstructorInfo cns =
                cl.GetConstructor(Type.EmptyTypes);
            MethodInfo met = cl.GetMethod(methName);
            Type rt = met.ReturnType;
            if (!rt.IsAssignableFrom(typeof(string)))
            {
                throw new InvalidOperationException(E_RET);
            }

            object o = cns.Invoke(null);
            string result = (string) met.Invoke(o, null);
            Console.WriteLine(L_OK + result);
        }
    }
}