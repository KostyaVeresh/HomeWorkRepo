open System

let rec differElems (list : int list) =
    let rec compare num =
        match num with
        | x when x = list.Length -> true
        | _ when list.Head = list.[num] -> false
        | _ -> compare (num + 1)

    match list with
    | [] -> true
    | _ when compare 1 -> differElems list.Tail
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
