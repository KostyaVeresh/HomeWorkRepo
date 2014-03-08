open System

//Returns reversed list
let rec reverse list =
    match list with
    | [] -> []
    | h::t -> reverse(list.Tail) @ [h]

[<EntryPoint>]
let main argv =
    let list = [1..10]
    let newList = reverse list
    Console.WriteLine(newList)
    Console.ReadLine();
    0