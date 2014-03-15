open System

let rec numMult num =
    match num / 10 with
    | 0 -> num
    | _ -> numMult(num / 10) * (num % 10)

[<EntryPoint>]
let main argv = 
    let res = numMult 12345
    printf "%d" res
    ignore(Console.ReadLine())
    0
