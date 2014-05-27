open System
open System.Collections
open System.Collections.Generic

type TreeNode<'a> =
    | TreeNode of 'a * TreeNode<'a> * TreeNode<'a>
    | Empty

type Iterator<'a>(tree : TreeNode<'a>) =
    let rec toList = function
    | Empty -> []
    | TreeNode(elem, left, right) -> toList(left) @ elem :: toList(right)
    let mutable list = toList tree
    let mutable currentPos = -1
    interface IEnumerator with
        member this.MoveNext() =
            if (currentPos + 1) < list.Length then
                currentPos <- currentPos + 1
                true
            else false
        member this.Current = box list.[currentPos]
        member this.Reset() = currentPos <- -1

type Tree() =
    let mutable node = TreeNode.Empty
    member this.Add(value) =
        let rec insert value tree=
            match tree with
            | Empty -> TreeNode(value, Empty, Empty)
            | TreeNode(v, left, right) when value < v -> 
                TreeNode(v, insert value left, right)
            | TreeNode(v, left, right) when value > v -> 
                TreeNode(v, left, insert value right)
            | TreeNode(_, _, _) as n -> n
        node <- insert (value) (node)
    interface IEnumerable with
        member this.GetEnumerator() = new Iterator<'a>(node) :> IEnumerator