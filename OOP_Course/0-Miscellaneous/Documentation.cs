namespace PartOne
{
    /// <summary>
    /// Class level summary documentation...</summary>
    /// <remarks>Longer comments...
    /// <para>other comments...</para>
    /// <para>other comments...</para>
    /// </remarks>
    public class Documentation
    {
        /// <summary>The class constructor.</summary>
        public Documentation()
        {
        }

        /// <summary>Desc. for SomeMethod.</summary>
        /// <param name="s">Description for s</param>
        /// <seealso cref="String">Reference to a type or
        /// member.</seealso>
        public void SomeMethod(string s)
        {
        }

        /// <summary>Some other method.</summary>
        /// <returns>Return results descr.</returns>
        /// <seealso cref="SomeMethod(string)">
        /// Notice the use of the cref attribute to
        /// reference a specific method </seealso>
        public int SomeOtherMethod()
        {
            return 0;
        }

        /// <summary>
        /// The entry point for the application.
        /// </summary>
        /// <param name="args"> A list of command line
        /// arguments</param>
        public static void Main(string[] args)
        {
        }
    }
}
