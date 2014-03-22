type Operation =
    | Addition
    | Substraction
    | Multiplication
    | Division

type CountTree =
    | Tree of Operation * CountTree * CountTree
    | Leaf of int

let rec counter tree =
    match tree with
    | Leaf value -> value
    | Tree(oper, left, right) ->
        match oper with
        | Addition -> (counter left) + (counter right)
        | Substraction -> (counter left) - (counter right)
        | Multiplication -> (counter left) * (counter right)
        | Division -> (counter left) / (counter right)

[<EntryPoint>]
let main argv = 
    0
