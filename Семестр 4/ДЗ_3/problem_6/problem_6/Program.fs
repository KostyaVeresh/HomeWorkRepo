open System

let primeNum =
    let prime num =
        let rec primeRec acc =
            match num with
            | 1 | 2 -> true
            | _ when num % acc = 0 -> false
            | _ when acc * acc > num -> true
            | _ -> primeRec (acc + 1)
        primeRec 2
    Seq.filter (prime) (Seq.initInfinite (fun x -> x))

[<EntryPoint>]
let main argv = 
    let seq = primeNum
    printf "%A" seq
    ignore(Console.ReadLine())
    0