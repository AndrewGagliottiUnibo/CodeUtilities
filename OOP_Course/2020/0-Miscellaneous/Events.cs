using System;

namespace PartOne
{
    public class EventEmitter
    {
        public event EventHandler OnSomethingHappened;

        public event EventHandler<string> OnSomethingElseHappened;

        // [...]

        private void DoThings()
        {
            // [...] do something

            // if there are subscribers, the event is not null
            if (OnSomethingHappened != null)
            {
                this.OnSomethingHappened(this, EventArgs.Empty);
            }

            // you can also use null propagation check:
            this.OnSomethingElseHappened?.Invoke(this, "foo");
        }
    }

    public class EventSubscriber
    {
        public EventSubscriber(EventEmitter publisher)
        {
            // you can register a method delegate ...
            publisher.OnSomethingHappened += this.HandleEvent;

            // ... or an anonymous delegate ...
            publisher.OnSomethingElseHappened += delegate(object sender, string args) { Console.WriteLine(args); };

            // ... o a lambda delegate ...
            publisher.OnSomethingHappened += (sender, args) => Console.WriteLine(args);
        }

        public void HandleEvent(object emitter, EventArgs args)
        {
            Console.WriteLine("Event received");
        }
    }
}
