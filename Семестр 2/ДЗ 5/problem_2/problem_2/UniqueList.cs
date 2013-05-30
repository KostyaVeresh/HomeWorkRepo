using System;

namespace problem_2
{
    public class UniqueList : List
    {
        public override void AddElem(int elem)
        {
            if (Exists(elem))
                throw new AddExistentElementException("This element is existent");
            base.AddElem(elem);
        }

        public override void DeleteElem(int value)
        {
            if (!Exists(value))
                throw new DeleteNonexistentElementException("There is no " + value + " element");
            base.DeleteElem(value);
        }
    }
}
