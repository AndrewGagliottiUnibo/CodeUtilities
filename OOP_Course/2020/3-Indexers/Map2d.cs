using System;
using System.Collections.Generic;
using System.Linq;

namespace Indexer
{
    class Map2d<TKey1, TKey2, TValue>
    {
        private IDictionary<Tuple<TKey1, TKey2>, TValue> _entries = new Dictionary<Tuple<TKey1, TKey2>, TValue>();

        public TValue this[TKey1 k1, TKey2 k2]
        {
            get { return this._entries[Tuple.Create(k1, k2)]; }
            set { this._entries[Tuple.Create(k1, k2)] = value; }
        }

        public override string ToString()
        {
            return string.Join(",\n", this._entries
                .Select(kv => $"({kv.Key.Item1}, {kv.Key.Item2}) -> {kv.Value}"));
        }
    }
}
