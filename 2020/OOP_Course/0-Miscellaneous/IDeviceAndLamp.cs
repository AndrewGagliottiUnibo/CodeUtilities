namespace PartOne
{
    public interface IDevice
    {
        void SwitchOn();
        void SwitchOff();
        bool IsSwitchedOn();
    }

    public class Lamp : IDevice
    {
        private bool switchedOn;

        public void SwitchOn()
        {
            this.switchedOn = true;
        }

        public void SwitchOff()
        {
            this.switchedOn = false;
        }

        public bool IsSwitchedOn()
        {
            return this.switchedOn;
        }
    }
}