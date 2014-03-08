open System

let listPowerTwo () =
    let rec makeList n =
        match n with
        | 0 -> []
        | _ -> makeList(n - 1) @ [pown 2 n]
    makeList 5 

        
[<EntryPoint>]
let main argv = 
    let list = listPowerTwo()
    Console.WriteLine(list);
    Console.ReadLine();
    0