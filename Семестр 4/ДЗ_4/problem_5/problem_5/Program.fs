open System

type BinTree = 
    | Tree of int * BinTree * BinTree
    | Leaf of int

let rec mapTree (tree: BinTree) mapFunc =
    match tree with
    | Tree(value, left, right) -> Tree(mapFunc value, mapTree left mapFunc, mapTree right mapFunc)
    | Leaf(value) -> Leaf(mapFunc value)

[<EntryPoint>]
let main argv = 
    ignore(Console.ReadLine())
    0
