open System

let maxPair (list: int list) =
    let rec checkPairs pos acc =
        if pos + 1 = list.Length then acc
        else
           if list.[pos]+list.[pos+1] > list.[acc]+list.[acc+1] then
              checkPairs (pos+1) pos
           else
              checkPairs (pos+1) acc
    checkPairs 0 0 + 1
            
              
                              

[<EntryPoint>]
let main argv = 
    let list1 = [1..5000]@[5000..1]
    let res = maxPair list1
    printfn "%d" res
    ignore(Console.ReadLine())
    0