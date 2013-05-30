using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace problem_2
{
    public class Set<T>
    {
        private List<T> elemSet = new List<T>();


        /// <summary>
        /// Creates empty set;
        /// </summary>
        public Set()
        {
        }

        private Set(List<T> elems)
        {
            elemSet.AddRange(elems);
        }


        /// <summary>
        /// Returns true if value exists in current set
        /// </summary>
        /// <param name="elem"></param>
        /// <returns></returns>
        public bool Exists(T elem)
        {
            return elemSet.Contains(elem);
        }

        /// <summary>
        /// Add element to current set
        /// </summary>
        /// <param name="elem"></param>
        public void AddElem(T elem)
        {
            if (!Exists(elem))
                elemSet.Add(elem);
        }

        /// <summary>
        /// Delete element if it exists
        /// </summary>
        /// <param name="elem"></param>
        public void deleteElem(T elem)
        {
            if (Exists(elem))
                elemSet.Remove(elem);
        }

        /// <summary>
        /// Union with specified set
        /// </summary>
        /// <param name="set"></param>
        /// <returns></returns>
        public Set<T> Union(Set<T> set)
        {
            return new Set<T>(elemSet.Union(set.elemSet).ToList());
        }

        /// <summary>
        /// Intersection with specified set
        /// </summary>
        /// <param name="set"></param>
        /// <returns></returns>
        public Set<T> Intersection(Set<T> set)
        {
            return new Set<T>(elemSet.Intersect(set.elemSet).ToList());
        }
    }
}
