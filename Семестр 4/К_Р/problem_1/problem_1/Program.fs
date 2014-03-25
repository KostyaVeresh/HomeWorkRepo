open System

let mediumSin (list: float list) =
    let rec medium (list: float list) acc =
        match list with
        | [] -> acc
        | _ -> medium list.Tail (acc + sin list.Head)
    (medium list 0.0) / (float list.Length )

[<EntryPoint>]
let main argv = 
    let list = [Math.PI/2.0; Math.PI/3.0; Math.PI/4.0; Math.PI/6.0]
    let res = mediumSin list
    printfn "%f" res
    ignore(Console.ReadLine())
    0
