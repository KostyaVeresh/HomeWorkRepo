open System

let rec differElems (list : int list) =
    let rec compare list elem =
        match list with
        | [] -> true
        | h::t when h = elem -> false
        | _ -> compare list.Tail elem

    match list with
    | [] -> true
    | h::t when compare t h -> differElems list.Tail
    | _ -> false

[<EntryPoint>]
let main argv = 
    let list = [1..1000]
    if differElems list then
        printf "different"
    else
        printf "some elems equal"
    ignore(Console.ReadLine())
    0
