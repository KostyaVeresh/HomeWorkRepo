open System

type Tree<'a> =
    | Tree of 'a * Tree<'a> * Tree<'a>
    | Leaf of 'a

let rec countTree tree =
    match tree with
    | Leaf _ -> 1
    | Tree (_, left, right) -> 1 + max (countTree left) (countTree right)

[<EntryPoint>]
let main argv = 
    0