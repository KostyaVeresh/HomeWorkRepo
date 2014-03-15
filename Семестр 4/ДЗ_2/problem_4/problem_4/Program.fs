open System

let firstPos num (list: int list) =
    let rec findPos acc (list: int list) =
        if list.Head = num then 
          acc
        else
          findPos (acc + 1) list.Tail
    findPos 1 list   
    
[<EntryPoint>]
let main argv = 
    let list = [1..100000]
    let res = firstPos 99999 list
    printfn "%d" res
    ignore(Console.ReadLine());
    0
