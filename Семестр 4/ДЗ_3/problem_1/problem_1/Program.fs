open System

let maxPair (list: int list) =
    let rec checkPairs list acc max maxPos =
        match list with
        | [] -> failwith "Empty array"
        | [h] -> acc
        | h :: t ->
            let pair = h + t.Head
            if pair > max then
                checkPairs list.Tail (acc + 1) pair acc
            else
                checkPairs list.Tail (acc + 1) max maxPos
    checkPairs list 0 0 0
              
                              

[<EntryPoint>]
let main argv = 
    let list1 = [1..5000]@[5000..1]
    let res = maxPair list1
    printfn "%d" res
    ignore(Console.ReadLine())
    0