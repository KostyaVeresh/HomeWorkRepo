open System

let func1 (list: int list) =
    (List.filter (fun x -> x % 2 = 0) list).Length

let func2 (list: int list) =
    (List.filter (fun x -> x <> 0) (List.map (fun x -> match x % 2 with |0 -> x | _ -> 0) list)).Length

let func3 (list: int list) =
    list.Length - List.fold (fun acc x -> acc + x % 2) 0 list


[<EntryPoint>]
let main argv = 
    let list = [1;4;3;4;5;7;9;6]
    let res1 = func1 list
    let res2 = func2 list
    let res3 = func3 list
    printfn "%d %d %d" res1 res2 res3
    ignore(Console.ReadLine())
    0
