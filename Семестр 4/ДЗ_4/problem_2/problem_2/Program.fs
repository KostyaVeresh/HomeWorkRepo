open System

let listMap1 x l =
    List.map (fun y -> y * x) l

let listMap2 x =
    List.map ((*) <| x)

let listMap: int -> int list -> int list =
    List.map << (*)

[<EntryPoint>]
let main argv = 
    let list = [1;2;3]
    let res = listMap 2 list
    printf "%A" res
    ignore(Console.ReadLine())
    0