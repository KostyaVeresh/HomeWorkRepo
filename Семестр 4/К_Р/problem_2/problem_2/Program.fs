open System

let romb num =
    let rec dr n acc (sym: string) =
        match acc with
        | x when x = n -> ""
        | _ -> sym + dr n (acc + 1) sym
    let rec drawUp acc n =
        match n with
        | x when x = num + 1 -> ""
        | _ -> (dr (num - n) 0 " ") + (dr acc 0 "*") + "\n" + drawUp (acc + 2) (n + 1)
    let rec drawDown acc n =
        match n with
        | 0 -> ""
        | _ -> (dr (num - n) 0 " ") + (dr acc 0 "*") + "\n" + drawDown (acc - 2) (n - 1)
    drawUp 1 1 + drawDown (2 * num - 3) (num - 1)
            

    

[<EntryPoint>]
let main argv = 
    let res = romb 10
    printfn "%s" res
    ignore(Console.ReadLine())
    0
