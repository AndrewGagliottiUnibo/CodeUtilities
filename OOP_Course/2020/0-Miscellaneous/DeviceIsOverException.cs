using System;
using System.Collections.Generic;

namespace PartOne
{
    class DeviceIsOverException : Exception
    {
        public DeviceIsOverException(Object obj)
        {
        }
    }

    class Device
    {
        private bool _on = false;
        private IEnumerable<Device> list;

        public void on()
        {
            if (!_on)
            {
                throw new DeviceIsOverException(this);
            }
        }

        public void allOn()
        {
            foreach (Device d in this.list)
            {
                try
                {
                    d.on();
                }
                catch (DeviceIsOverException de)
                {
                    // do some stuff!
                }
            }
        }
    }
}